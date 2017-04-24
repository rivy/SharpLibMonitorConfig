#pragma once
#include <Windows.h>
#include "PhysicalMonitor.h"

using namespace System;
using namespace System::Collections::Generic;


namespace SharpLib::MonitorConfig
{

    /// <summary>
    /// Summary for VirtualMonitor
    /// </summary>
    public ref class VirtualMonitor
    {
    public:
        VirtualMonitor(HMONITOR aHandle);
        ~VirtualMonitor();

    private:
        HMONITOR iHandle;
        MONITORINFOEX* iInfo;
        DWORD iPhysicalMonitorCount;
        PHYSICAL_MONITOR* iPhysicalMonitorArray;
        // A virtual monitor has a collection of physical monitor
        List<PhysicalMonitor^> iPhysicalMonitors;
    };
}