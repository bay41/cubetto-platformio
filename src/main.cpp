#include <SPI.h>
#include <cubetto.h>
#include <AccelStepper.h>

Cubetto CubettoRobot;

void setup()
{

    SPI.begin();
    SPI.setBitOrder(LSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV16);

    CubettoRobot.begin();                            // Setup Robot
    CubettoRobot.startAdvertisingBluetooth(0, true); // Start Advertising and Auto
}

void oneSecondLoop(void)
{
    static uint32_t counter = 0;
    counter++;
    if (counter > 0xFFFF)
    {
        counter = 0;
        CubettoRobot.updateBatteryLevel();
        CubettoRobot.sendBatteryLevelToBluetooth();
    }
}

void loop()
{
    CubettoRobot.bluetoothTasks();
    if (CubettoRobot.checkForBluetoothMessage())
    {
        CubettoRobot.decodeInterfaceInstructions(CubettoRobot.bluetoothMessageCommand);
    }

    // Tasks to call every 1 second
    oneSecondLoop();
}
