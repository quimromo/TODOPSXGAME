// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "tdBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TDLEVELEDITOR_API UtdBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="td")
	static void WriteStringToDisk(FString stringToWrite, FString filename, FString exportDir);

	UFUNCTION(BlueprintCallable, Category="td")
	static void ExportAssetToPath(UObject* assetToExport, FString exportPath);
};
