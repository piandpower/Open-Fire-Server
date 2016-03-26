// Free to use

#include "OpenFire.h"
#include "StrongPointDTO.h"

StrongPointDTO::StrongPointDTO(const FString& string)
{
	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(string);

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>>& strongPoints = JsonObject->GetArrayField("strongpoints");
		for (const TSharedPtr<FJsonValue>& strongPoint : strongPoints)
		{
			Data data;

			const TSharedPtr<FJsonObject>& jsonObject = strongPoint->AsObject();
			data.strongPointID = jsonObject->GetIntegerField("strongpoint_id");
			data.location.X = jsonObject->GetNumberField("position_x");
			data.location.Y = jsonObject->GetNumberField("position_y");

			datas.Add(data);
		}
	}
}
