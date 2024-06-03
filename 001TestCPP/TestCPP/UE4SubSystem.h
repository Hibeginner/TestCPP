#pragma once
#include <memory>

class UEWidget;

class UE4SubSystem
{
public:
	
	std::weak_ptr<UEWidget> UEWidgetWeakPtr;

	static UE4SubSystem& GetInstance() {
		static UE4SubSystem _inst;
		return _inst;
	}
	void SetUEWidget(UEWidget* UEWidgetPtr);

	void OnViewChange();
	void DataChageCallWidget();
};

