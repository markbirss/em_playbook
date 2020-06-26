#ifndef _GUARD_H_METAL
#define _GUARD_H_METAL

//this renders basic text, when user-facing error signals / instructions are thrown
//usually works during factory reset as backup (or during a corrupt FS as all apps are gone)

#include "defs.h"
#include "hal-pins.h"
#include "hal-io.h"
#include "hal-network.h"
#include "hal-fs.h"
#include "hal-display.h"
#include "app-engine.h"

String message = "  OS Bootstrap\n\n";
void metal_render_handler()
{
    bool changed = false;

    if (SIG_WIFI_STATE.resolved && SIG_WIFI_STATE.value == WIFI_STATE_NO_CONFIG)
    {
        changed = true;
        message += "  Wi-Fi reconfigure Needed:\n  Please config network by holding down the round button (for 6 seconds)\n\n";
        signal_resolve(&SIG_WIFI_STATE);
    }
    if (SIG_WIFI_STATE.resolved && SIG_WIFI_STATE.value == WIFI_STATE_CONNECTING)
    {
        changed = true;
        message += "  Wi-Fi Connection in process\n\n";
        signal_resolve(&SIG_WIFI_STATE);
    }
    if (SIG_WIFI_STATE.resolved && SIG_WIFI_STATE.value == WIFI_STATE_FAILED)
    {
        changed = true;
        message += "  Wi-Fi Connection Failed\n\n";
        message += "  Reconfigure Needed:\n  Please config network by holding down the round button (for 6 seconds)\n\n";
        signal_resolve(&SIG_WIFI_STATE);
    }
    if (SIG_WIFI_STATE.resolved && SIG_WIFI_STATE.value == WIFI_STATE_NO_MORE_TRY)
    {
        changed = true;
        message += "  Wi-Fi reconfigure Needed:\n  Please config network by holding down the round button (for 6 seconds)\n\n";
        signal_resolve(&SIG_WIFI_STATE);
    }
    if (SIG_WIFI_STATE.resolved && SIG_WIFI_STATE.value == WIFI_STATE_CONNECTED)
    {
        changed = true;
        message += "  Wi-Fi is Connected :)\n\n";
        signal_resolve(&SIG_WIFI_STATE);
    }
    if (SIG_PORTAL_STATE.resolved && SIG_PORTAL_STATE.value > 0)
    {
        changed = true;
        message.clear();
        message += "  Wi-Fi Configurator is up, Please connect to \n\n";
        message += "  [ EM-Paper ]\n\n";
        message += "  to setup your device's network\n";
        message += "  \n\n";
        message += "  This Configurator will stay online for 120 seconds\n\n";
        message += "  If you want to cancel, press and hold the button again for 6 seconds.\n\n";
        signal_resolve(&SIG_PORTAL_STATE);
    }
    if (SIG_PORTAL_STATE.resolved && SIG_PORTAL_STATE.value == 0)
    {
        changed = true;
        message.clear();
        message += "  Wi-Fi Configurator canceled.\n\n  System shutting down soon.\n\n";
        signal_resolve(&SIG_PORTAL_STATE);
    }

    if (SIG_WAKE_REASON.resolved)
    {
        signal_resolve(&SIG_WAKE_REASON);
        changed = true;
        message.clear();
        message += "  System Missing.\n\n  The OS will try to bootstrap\n\n  when there's network.";
    }
    if (SIG_BEFORE_SLEEP.resolved)
    {
        signal_resolve(&SIG_BEFORE_SLEEP);
        changed = true;
        message.clear();
        message += "  System Missing.\n\n  Ready to sleep\n\n  Touch or spin to wake up.\n\n  Hold down the knob for 6 seconds to configure Wi-Fi.";
    }
    else
    {
        //NOTE, IF SIG_BEFORE_SLEEP IS NOT PROCESSED
        //THE OS IS CONSIDERED BROKEN!!
        signal_raise(&SIG_SYS_BROKE, 1); //this should trigger full download next time.
    }
    if (SIG_APP_UPT_STATE.resolved && SIG_APP_UPT_STATE.value == APP_UPT_STATE_FAILED)
    {
        signal_resolve(&SIG_APP_UPT_STATE);
        changed = true;
        message += "  App bundle downloader failed\n\n  Remote might be down, or it could be Wi-Fi reasons.";
    }
    if (changed)
    {
        display_dbg_print(message);
    }
}

#endif