// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorUtilityLibrary.h"
#include "Engine/Texture.h"
#include "EditorAssetLibrary.h"
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

#pragma region CheckPowerOfTwo
void UMyAssetActionUtility::CheckPowerOfTwo()
{
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

	uint32 Counter = 0;
	for (UObject* SeletctedObj : SelectedObjects) {
		if (ensure(SeletctedObj)) {
			UTexture* Tex = dynamic_cast<UTexture*>(SeletctedObj);
			if (ensure(Tex)) {
				int32 Width = static_cast<int32>(Tex->GetSurfaceWidth());
				int32 Height = static_cast<int32>(Tex->GetSurfaceHeight());
				if (IsPowerOfTwo(Width) && IsPowerOfTwo(Height)) {
					++Counter;
				}
				else{
					PrintToScreen(Tex->GetPathName() + " is not power of two !", FColor::Red);
				}
			}
		}
		else {
			PrintToScreen(SeletctedObj->GetPathName() + " is not a texture.", FColor::Red);
		}
	}
	GiveFeedBack("power of two", Counter);

}
#pragma endregion

#pragma region AddPrefix
void UMyAssetActionUtility::AddPrefix()
{
	TArray<UObject*> SelectedObjs = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter = 0;
	for (UObject* SelectedObject : SelectedObjs) {
		if (ensure(SelectedObject)) {
			const FString* Prefix = PrefixMap.Find(SelectedObject->GetClass());
			if (ensure(Prefix) && !Prefix->Equals("")) {
				FString OldName = SelectedObject->GetName();
				if (!OldName.StartsWith(*Prefix)) {
					FString NewName = *Prefix + OldName;
					UEditorUtilityLibrary::RenameAsset(SelectedObject,NewName);
					++Counter;
				}
			}
			else {
				PrintToScreen("Can't find prefix for class " + SelectedObject->GetClass()->GetName(), FColor::Red);
			}
			
		}
		
	}
	GiveFeedBack("Added prefix to", Counter);
}
#pragma endregion

#pragma region CleanupFolder
void UMyAssetActionUtility::CleanupFolder(FString ParentFolder) {

	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 Counter = 0;
	for (UObject* SelectedObject : SelectedObjects) {
		if (ensure(SelectedObject)) {
			FString NewPath = FPaths::Combine(ParentFolder, SelectedObject->GetClass()->GetName(),SelectedObject->GetName());
			if (UEditorAssetLibrary::RenameLoadedAsset(SelectedObject, NewPath)) {
				++Counter;
			}
		}
	}

	GiveFeedBack("Moved", Counter);
}
#pragma endregion


#pragma region Helper

void UMyAssetActionUtility::PrintToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine)) {
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

bool UMyAssetActionUtility::IsPowerOfTwo(int32 NumberToCheck)
{
	if (NumberToCheck == 0) {
		return false;
	}
	return(NumberToCheck & (NumberToCheck - 1)) == 0;
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