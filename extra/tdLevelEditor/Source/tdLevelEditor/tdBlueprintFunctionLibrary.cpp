// Fill out your copyright notice in the Description page of Project Settings.


#include "tdBlueprintFunctionLibrary.h"

#include "AssetSelection.h"
#include "AssetToolsModule.h"

void UtdBlueprintFunctionLibrary::WriteStringToDisk(FString stringToWrite, FString filename, FString exportDir)
{
	if(exportDir.IsEmpty())
	{
		exportDir = FPaths::ProjectContentDir() + "/out/";
	}
	FFileHelper::SaveStringToFile(stringToWrite, *(exportDir + filename));
}

void UtdBlueprintFunctionLibrary::ExportAssetToPath(UObject* assetToExport, FString exportPath)
{
	TArray<UObject*> assetsToExport;
	assetsToExport.Add(assetToExport);
	FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
	AssetToolsModule.Get().ExportAssets(assetsToExport, exportPath);
}
