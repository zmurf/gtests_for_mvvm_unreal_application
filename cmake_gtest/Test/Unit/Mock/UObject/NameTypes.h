#pragma once

class FName
{
public:
    FName() = default;
    FName(FName&&) = default;
    FName(const FName&) = default;
    FName& operator=(FName&&) = default;
    FName& operator=(const FName&) = default;

    char16_t Data[64];
};