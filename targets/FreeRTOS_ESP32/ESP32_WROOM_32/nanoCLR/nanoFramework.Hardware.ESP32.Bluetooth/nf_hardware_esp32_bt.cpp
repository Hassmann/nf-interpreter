#include "nf_hardware_esp32_bt.h"

static const CLR_RT_MethodHandler method_lookup[] =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeInitializeDevice___STATIC__VOID__STRING__nanoFrameworkHardwareEsp32BluetoothBluetoothMode__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativePrepareGatt___STATIC__VOID__SZARRAY_I4__I4__I4__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeBeginService___STATIC__VOID__I4__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeBeginCharacteristic___STATIC__VOID__I4__I4__I4__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeAddEntry___STATIC__VOID__I4__SZARRAY_U1__BOOLEAN__I4__I4__SZARRAY_U1,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeFinalizeService___STATIC__VOID__I4__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeGetValue___STATIC__SZARRAY_U1__I4__I4,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeSetValue___STATIC__VOID__I4__I4__SZARRAY_U1,
    Library_nf_hardware_esp32_bt_nanoFramework_Hardware_Esp32_Bluetooth_BluetoothHost::NativeAdvertise___STATIC__VOID__SZARRAY_U1__I4__I4,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

const CLR_RT_NativeAssemblyData g_CLR_AssemblyNative_nanoFramework_Hardware_Esp32_Bluetooth =
{
    "nanoFramework.Hardware.Esp32.Bluetooth",
    0xE3D0163B,
    method_lookup,
    { 1, 0, 0, 0 }
};
