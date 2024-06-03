#include "UEWidget.h"
#include "UE4SubSystem.h"
#include <iostream>

UEWidget::UEWidget()
{
	UE4SubSystem::GetInstance().SetUEWidget(this);
}

UEWidget::~UEWidget()
{
}

void UEWidget::OnCheckboxSelected()
{
	UE4SubSystem::GetInstance().OnViewChange();
}

void UEWidget::SelectCheckbox()
{
	std::cout << "SelectCheckbox" << std::endl;
}
