// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorUtilityLibrary.h"
#include "MyAssetActionUtility.h"

#pragma region RenameSelectedAssets

void UMyAssetActionUtility::RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase)
{
	if (SearchPattern.IsEmpty() || SearchPattern == ReplacePattern) {
		return;
	}
	TArray<UObject*> SelectedObjects;
	SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter = 0;
	for (UObject* SelectedObject : SelectedObjects) {
		if (ensure(SelectedObject)) {
			FString AssetName = SelectedObject->GetName();
			if (AssetName.Contains(*SearchPattern, SearchCase)) {
				FString NewName = AssetName.Replace(*SearchPattern, *ReplacePattern, SearchCase);
				UEditorUtilityLibrary::RenameAsset(SelectedObject, NewName);
				++Counter;
			}
		}
	}
	GiveFeedBack(TEXT("Renamed"), Counter);
}

#pragma endregion

#pragma region Helper
void UMyAssetActionUtility::PrintToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine)) {
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

void UMyAssetActionUtility::GiveFeedBack(FString Method, uint32 Counter)
{
	FString Message = FString("No matching files found!"); //
	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0) {
		Message = Method.AppendChar(' ');//assign message to new.
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
	}
	PrintToScreen(Message, Color);
}
#pragma endregion