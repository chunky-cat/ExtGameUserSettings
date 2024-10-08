// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtGameUserSettings.h"

#include "Internationalization/Culture.h"

UExtGameUserSettings::UExtGameUserSettings(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	AudioVolumeMaster = 1.0f;
	AudioVolumeMusic = 1.0f;
	AudioVolumeEffects = 1.0f;
	Culture = FInternationalization::Get().GetCurrentLanguage()->GetName();
}

float UExtGameUserSettings::GetAudioVolume(EAudioVolumeSettingsType Type) const
{
	switch (Type)
	{
	case EAudioVolumeSettingsType::Audio_Volume_Settings_Music:
		return AudioVolumeMusic;
	case EAudioVolumeSettingsType::Audio_Volume_Settings_Effects:
		return AudioVolumeEffects;
	case EAudioVolumeSettingsType::Audio_Volume_Settings_Master:
		return AudioVolumeMaster;
	default: return 0;
	}
}

void UExtGameUserSettings::SetAudioVolume(EAudioVolumeSettingsType Type, float Value)
{
	switch (Type)
	{
		case EAudioVolumeSettingsType::Audio_Volume_Settings_Music:
			AudioVolumeMusic = Value;
			break;
		case EAudioVolumeSettingsType::Audio_Volume_Settings_Effects:
			AudioVolumeEffects = Value;
			break;
		case EAudioVolumeSettingsType::Audio_Volume_Settings_Master:
			AudioVolumeMaster = Value;
			break;
		default: break;
	}
}

void UExtGameUserSettings::SetCulture(FString Value)
{
	Culture = Value;
	FInternationalization::Get().SetCurrentCulture(Value);
}

UExtGameUserSettings* UExtGameUserSettings::GetExtGameUserSettings()
{
	return Cast<UExtGameUserSettings>(UGameUserSettings::GetGameUserSettings());
}
