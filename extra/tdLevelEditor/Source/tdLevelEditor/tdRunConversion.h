// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraphSchema_K2.h"
#include "GameplayTask.h"
#include "tdRunConversion.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConversionFinished);


USTRUCT(BlueprintType)
struct FMeshAndTextureData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SizeX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SizeY = 0;
};

/**
 * 
 */
UCLASS(Config="Game")
class TDLEVELEDITOR_API UtdRunConversion : public UGameplayTask
{
	GENERATED_BODY()

public:

	UtdRunConversion(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UtdRunConversion* CreateProxyObjectForConversion(TMap<FName, FMeshAndTextureData> meshInfoData, FString tempDir, FString outDir);

	UPROPERTY(BlueprintAssignable)
	FOnConversionFinished OnConversionFinished;

private:
	void StartConversionProcess(TMap<FName, FMeshAndTextureData> meshInfoData, FString tempDir, FString outDir);

protected:
	UPROPERTY(Config)
	FString FBXConvertorLocation;
	UPROPERTY(Config)
	FString PNGQuantizerLocation;
	UPROPERTY(Config)
	FString IMG2TimLocation;
	UPROPERTY(Config)
	FString WorkingDir;

};
