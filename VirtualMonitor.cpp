#include "stdafx.h"
#include "VirtualMonitor.h"

namespace SharpLib::MonitorConfig
{
    /**
    */
    VirtualMonitor::VirtualMonitor(HMONITOR aHandle) : iHandle(aHandle)
    {
        iInfo = new MONITORINFOEX();
        iInfo->cbSize = sizeof(MONITORINFOEX); //Need to set this to allow next function to identify Structure type

        if (GetMonitorInfo(aHandle, iInfo) == 0)
        {
            //TODO: handle error
            // Throw exception?
        }

        // Check how many physical monitor do we have
        DWORD count = 0;
        GetNumberOfPhysicalMonitorsFromHMONITOR(aHandle, &count);
        iPhysicalMonitorCount = count; // Keep track of our count

        // Fetch physical monitors
        if (count > 0) //Defensive
        {
            iPhysicalMonitorArray = new PHYSICAL_MONITOR[count];
            GetPhysicalMonitorsFromHMONITOR(aHandle, count, iPhysicalMonitorArray);
        }

        for (DWORD i = 0; i<count; i++)
        {
            //Create Physical Monitors
            iPhysicalMonitors.Add(gcnew PhysicalMonitor());
        }

    }

    /**
    TODO: Check if we ought to use finalizer or dispose instead?
    */
    VirtualMonitor::~VirtualMonitor()
    {
        delete iPhysicalMonitorArray;
    }
}