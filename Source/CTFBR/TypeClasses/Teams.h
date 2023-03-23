#pragma once

UENUM(BlueprintType)
enum class ETeam : uint8
{
	ET_RedTeam UMETA(DisplayName = "RedTeam"),
	ET_BlueTeam UMETA(DisplayName = "BlueTeam"),
	ET_GreenTeam UMETA(DisplayName = "GreenTeam"),
	ET_BlackTeam UMETA(DisplayName = "BlackTeam"),
	ET_OrangeTeam UMETA(DisplayName = "OrangeTeam"),
	ET_Spectator UMETA(DisplayName = "Spectator"),

	ET_MAX UMETA(DisplayName = "DefaultMAX")
};