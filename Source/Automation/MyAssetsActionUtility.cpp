// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAssetsActionUtility.h"
#include "EditorUtilityLibrary.h"

#pragma region RenameSelectedAssets

void UMyAssetsActionUtility::RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase){

	//Check if something needs to be done.
	if (SearchPattern.IsEmpty() || SearchPattern.Equals(ReplacePattern, SearchCase)){
		return;
	}
	//get selected objects
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

	uint32 Counter = 0;

	for (UObject* SelectedObject : SelectedObjects) {
		if (ensure(SelectedObject)) {
			FString AssetName = SelectedObject->GetName();
			FString NewName = AssetName.Replace(*SearchPattern, *ReplacePattern, SearchCase);
			UEditorUtilityLibrary::RenameAsset(SelectedObject, NewName);
			++Counter;
		}
	}

	GiveFeedBack(TEXT("Renamed"), Counter);

}

#pragma endregion

#pragma region Helper

void UMyAssetsActionUtility::PrintToScreen(FString Message, FColor Color){

	if (ensure(GEngine)) {
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}
void UMyAssetsActionUtility::GiveFeedBack(FString Method, uint32 Counter)
{
	FString Message = FString("No matching files found!");
	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0) {
		Message = Method.AppendChar(' ');
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));

	}
	PrintToScreen(Message, Color);

}
#pragma endregion