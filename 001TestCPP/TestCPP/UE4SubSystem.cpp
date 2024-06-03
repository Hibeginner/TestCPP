#include "UE4SubSystem.h"
#include "UEWidget.h"
#include <iostream>

void UE4SubSystem::SetUEWidget(UEWidget* UEWidgetPtr)
{
	std::shared_ptr<UEWidget> ptr(UEWidgetPtr);
	UEWidgetWeakPtr = ptr;// std::make_shared<UEWidget>(UEWidgetPtr);
}

void UE4SubSystem::OnViewChange()
{
	std::cout << "OnViewChange" << std::endl;
}

void UE4SubSystem::DataChageCallWidget()
{
	if (std::shared_ptr<UEWidget> tempPtr = UEWidgetWeakPtr.lock()) {
		tempPtr->SelectCheckbox();
	}
}
