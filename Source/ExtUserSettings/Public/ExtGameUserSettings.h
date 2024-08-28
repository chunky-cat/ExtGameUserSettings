// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "ExtGameUserSettings.generated.h"


UENUM(BlueprintType)
enum class EAudioVolumeSettingsType : uint8
{
	Audio_Volume_Settings_Master = 0,
	Audio_Volume_Settings_Music = 1,
	Audio_Volume_Settings_Effects = 2,
};

UCLASS()
class EXTUSERSETTINGS_API UExtGameUserSettings : public UGameUserSettings
{
	GENERATED_UCLASS_BODY()
public:
	/// Getter
	UFUNCTION(BlueprintCallable) float GetAudioVolume(EAudioVolumeSettingsType Type ) const;
	UFUNCTION(BlueprintCallable) float GetAudioVolumeMaster( ) const { return AudioVolumeMaster; };
	UFUNCTION(BlueprintCallable) float GetAudioVolumeMusic() const { return AudioVolumeMusic; };
	UFUNCTION(BlueprintCallable) float GetAudioVolumeEffects() const  { return AudioVolumeEffects; };
	/// Setter
	UFUNCTION(BlueprintCallable) void SetAudioVolume(EAudioVolumeSettingsType Type, float Value );
	UFUNCTION(BlueprintCallable) void SetAudioVolumeMaster(float value) { AudioVolumeMaster = value; };
	UFUNCTION(BlueprintCallable) void SetAudioVolumeMusic(float value) { AudioVolumeMusic = value; };
	UFUNCTION(BlueprintCallable) void SetAudioVolumeEffects(float value) { AudioVolumeEffects = value; };

	
	UFUNCTION(BlueprintCallable) static UExtGameUserSettings* GetExtGameUserSettings();
protected:
	UPROPERTY(Config) float AudioVolumeMaster = 1;
	UPROPERTY(Config) float AudioVolumeMusic = 1;
	UPROPERTY(Config) float AudioVolumeEffects = 1;
};
