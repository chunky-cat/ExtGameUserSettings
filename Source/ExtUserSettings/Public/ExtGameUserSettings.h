// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "Modules/ModuleManager.h"
#include "ExtGameUserSettings.generated.h"


UENUM(BlueprintType)
enum class EAudioVolumeSettingsType : uint8
{
	Audio_Volume_Settings_Master = 0,
	Audio_Volume_Settings_Music = 1,
	Audio_Volume_Settings_Effects = 2,
};

UCLASS()
class EXTGAMEUSERSETTINGS_API UExtGameUserSettings : public UGameUserSettings
{
	GENERATED_UCLASS_BODY()

public: 
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") static UExtGameUserSettings* GetExtGameUserSettings();

	/// Getter
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") float GetAudioVolume(EAudioVolumeSettingsType Type ) const;
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") float GetAudioVolumeMaster( ) const { return AudioVolumeMaster; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") float GetAudioVolumeMusic() const { return AudioVolumeMusic; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") float GetAudioVolumeEffects() const  { return AudioVolumeEffects; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") FString GetCulture() const  { return Culture; };

	/// Setter
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") void SetAudioVolume(EAudioVolumeSettingsType Type, float Value );
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") void SetAudioVolumeMaster(const float Value) { AudioVolumeMaster = Value; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") void SetAudioVolumeMusic(const float Value) { AudioVolumeMusic = Value; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") void SetAudioVolumeEffects(const float Value) { AudioVolumeEffects = Value; };
	UFUNCTION(BlueprintCallable, Category="ExtGameUserSettings") void SetCulture(FString Value);
protected:
	UPROPERTY(Config) float AudioVolumeMaster = 1;
	UPROPERTY(Config) float AudioVolumeMusic = 1;
	UPROPERTY(Config) float AudioVolumeEffects = 1;

	UPROPERTY(Config) FString Culture;
};

////////////////// PLUGIN RELATED //////////////////////

class FExtGameUserSettingsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};