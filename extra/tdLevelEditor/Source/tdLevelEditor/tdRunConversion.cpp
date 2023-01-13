// Fill out your copyright notice in the Description page of Project Settings.


#include "tdRunConversion.h"

#include "Misc/MonitoredProcess.h"

UtdRunConversion::UtdRunConversion(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FBXConvertorLocation = FPaths::ProjectContentDir() + "/bin/FBX2PSX.exe";
	PNGQuantizerLocation = FPaths::ProjectContentDir() + "/bin/pngquant.exe";
	IMG2TimLocation = FPaths::ProjectContentDir() + "/bin/img2tim.exe";
	
	WorkingDir = FPaths::ProjectContentDir() + "/bin/";
}

UtdRunConversion* UtdRunConversion::CreateProxyObjectForConversion(TMap<FName, FMeshAndTextureData> meshInfoData, FString tempDir, FString outDir)
{
	UtdRunConversion* Proxy = NewObject<UtdRunConversion>();
	Proxy->StartConversionProcess(meshInfoData, tempDir, outDir);
	return Proxy;
}

void UtdRunConversion::StartConversionProcess(TMap<FName, FMeshAndTextureData> meshInfoData, FString tempDir, FString outDir)
{

	FBXConvertorLocation = FPaths::ProjectContentDir() + "/bin/FBX2PSX.exe";
	PNGQuantizerLocation = FPaths::ProjectContentDir() + "/bin/pngquant.exe";
	IMG2TimLocation = FPaths::ProjectContentDir() + "/bin/img2tim.exe";

	IPlatformFile &PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	class FQuodFillArrayDirectoryVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override
		{
			if (bIsDirectory)
			{
				Directories.Add(FilenameOrDirectory);
			}
			else
			{
				Files.Add(FilenameOrDirectory);
			}
			return true;
		}

		TArray<FName> Directories;
		TArray<FString> Files;
	};
		
	FQuodFillArrayDirectoryVisitor DirectoryVisitor;
	PlatformFile.IterateDirectoryRecursively(*tempDir, DirectoryVisitor);
	for( FString File : DirectoryVisitor.Files)
	{
		UE_LOG(LogTemp, Display, TEXT("Processing File: %s"),*File);

		if(File.EndsWith(".fbx"))
		{
			WorkingDir = FPaths::ProjectContentDir() + "/bin/";
			FString FileName = FPaths::GetBaseFilename(File);
			if(FMeshAndTextureData* data = meshInfoData.Find(FName(FileName)))
			{
				FString params = " -fbx " + File + " -outdir "+ outDir + " -vertex_format 2 -unrealMode 1 -yaw 180.0 -texture_size " + FString::FromInt(data->SizeX) + "," + FString::FromInt(data->SizeY);
				TSharedPtr<FMonitoredProcess> conversionProcess = MakeShareable(new FMonitoredProcess(FBXConvertorLocation, params, WorkingDir, false, false));
				conversionProcess->Launch();
				while(conversionProcess->Update());
			}
			
		}
		else if(File.EndsWith(".png"))
		{
			FString params = " --force --verbose --ordered --speed=1 --quality=50-90 " + File;
			TSharedPtr<FMonitoredProcess> quantizerProcess = MakeShareable(new FMonitoredProcess(PNGQuantizerLocation, params, WorkingDir, false, false));
			quantizerProcess->Launch();
			while(quantizerProcess->Update());

			FString timParams = " " + File;
			TSharedPtr<FMonitoredProcess> timConversionProcess = MakeShareable(new FMonitoredProcess(IMG2TimLocation, timParams, WorkingDir, false, false));
			timConversionProcess->Launch();
			while(timConversionProcess->Update());

			FString FileName = FPaths::GetBaseFilename(File);
			FString newFilePath = FString(outDir + "/" + FileName + ".tim");
			// Delete in case it already exists
			PlatformFile.DeleteFile(*newFilePath);
			// Move the file
			PlatformFile.MoveFile(*FString(outDir + "/textures/" + FileName + ".tim"), *File.Replace(TEXT(".png"),TEXT(".tim")));
			// Delete intermediary files
			PlatformFile.DeleteFile(*(File.Replace(TEXT(".png"),TEXT("")) + "-or8.png"));
		}
	}
	
	
	OnConversionFinished.Broadcast();
}
