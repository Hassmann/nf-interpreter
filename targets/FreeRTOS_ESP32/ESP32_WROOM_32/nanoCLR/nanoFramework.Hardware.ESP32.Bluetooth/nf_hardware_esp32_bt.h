//-----------------------------------------------------------------------------
//
//                   ** WARNING! ** 
//    This file was generated automatically by a tool.
//    Re-running the tool will overwrite this file.
//    You should copy this file to a custom location
//    before adding any customization in the copy to
//    prevent loss of your changes when the tool is
//    re-run.
//
//-----------------------------------------------------------------------------

#ifndef _NF_HARDWARE_ESP32_BT_H_
#define _NF_HARDWARE_ESP32_BT_H_

#include <nanoCLR_Interop.h>
#include <nanoCLR_Runtime.h>
#include <corlib_native.h>


struct Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost
{
    static const int FIELD_STATIC__isDeviceInitialized = 0;

    static const int FIELD__isTableCreated = 1;
    static const int FIELD__configuration = 2;
    static const int FIELD__services = 3;

    NANOCLR_NATIVE_DECLARE(NativeInitializeDevice___STATIC__VOID__STRING__nanoFrameworkHardwareEsp32BluetoothBluetoothMode__I4);
    NANOCLR_NATIVE_DECLARE(NativePrepareGatt___STATIC__VOID__SZARRAY_I4__I4__I4__I4);
    NANOCLR_NATIVE_DECLARE(NativeBeginService___STATIC__VOID__I4__I4);
    NANOCLR_NATIVE_DECLARE(NativeBeginCharacteristic___STATIC__VOID__I4__I4__I4__I4);
    NANOCLR_NATIVE_DECLARE(NativeAddEntry___STATIC__VOID__I4__SZARRAY_U1__BOOLEAN__I4__I4__SZARRAY_U1);
    NANOCLR_NATIVE_DECLARE(NativeFinalizeService___STATIC__VOID__I4__I4);
    NANOCLR_NATIVE_DECLARE(NativeGetValue___STATIC__SZARRAY_U1__I4__I4);
    NANOCLR_NATIVE_DECLARE(NativeSetValue___STATIC__VOID__I4__I4__SZARRAY_U1);
    NANOCLR_NATIVE_DECLARE(NativeAdvertise___STATIC__VOID__SZARRAY_U1__I4__I4);

    //--//

};

extern const CLR_RT_NativeAssemblyData g_CLR_AssemblyNative_nanoFramework_Hardware_Esp32_Bluetooth;

#endif  //_NF_HARDWARE_ESP32_BT_H_
