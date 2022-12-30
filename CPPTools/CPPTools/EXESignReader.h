#pragma once
#include <windows.h>
#include <wincrypt.h>
#include <wintrust.h>
#include <stdio.h>
#include <tchar.h>


typedef struct {
	LPWSTR lpszProgramName;
	LPWSTR lpszPublisherLink;
	LPWSTR lpszMoreInfoLink;
} SPROG_PUBLISHERINFO, * PSPROG_PUBLISHERINFO;

class EXESignReader
{
public:
	EXESignReader() = default;
	void ShowSignInfo();
};

