/**
 * SPDX-License-Identifier: LGPL-2.1-only
 * SPDX-FileCopyrightText: 2018-2020 Lasse K. Mikkelsen <lkmi@prevas.dk>, Prevas A/S (www.prevas.com)
 */

#ifndef __RAUC_INSTALLER_H__
#define __RAUC_INSTALLER_H__

#include <glib.h>

/**
 * @brief struct that contains the context of an Rauc installation.
 */
struct install_context {
        gchar *bundle;                /**< Rauc bundle file to install */
        GSourceFunc notify_event;     /**< Callback function */
        GSourceFunc notify_complete;  /**< Callback function */
        GMutex status_mutex;          /**< Mutex used for accessing status_messages */
        GQueue status_messages;       /**< Queue of status messages from Rauc DBUS */
        gint status_result;           /**< The result of the installation */
        GMainLoop *mainloop;          /**< The installation GMainLoop  */
        GMainContext *loop_context;   /**< GMainContext for the GMainLoop */
};

/**
 * @brief RAUC install bundle
 *
 * @param[in] bundle RAUC bundle file (.raucb) to install.
 * @param[in] on_install_notify Callback function to be called with status info during
 *                              installation.
 * @param[in] on_install_complete Callback function to be called with the result of the
 *                                installation.
 * @param[in] wait Whether to wait until install thread finished or not.
 * @return for wait=TRUE, TRUE if installation succeeded, FALSE otherwise; for
 *         wait=FALSE TRUE is always returned immediately
 */
gboolean rauc_install(const gchar *bundle, GSourceFunc on_install_notify,
                GSourceFunc on_install_complete, gboolean wait);

#endif // __RAUC_INSTALLER_H__
