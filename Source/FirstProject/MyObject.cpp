// Fill out your copyright notice in the Description page of Project Settings.

#include "MyObject.h"
#include "Kismet/KismetSystemLibrary.h"
UMyObject::UMyObject()
{
	my_float = 100;
}
float UMyObject::my_function(float value)
{
	//Printing on the Screen
	UKismetSystemLibrary::PrintString(this, TEXT("Printing on screen using  C++ from MyObject"));
	return value * value;
}