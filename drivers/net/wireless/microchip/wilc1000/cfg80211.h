/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2012 - 2018 Microchip Technology Inc., and its subsidiaries.
 * All rights reserved.
 */

#ifndef WILC_CFG80211_H
#define WILC_CFG80211_H
#include "netdev.h"

int wilc_cfg80211_init(struct wilc **wilc, struct device *dev, int io_type,
		       const struct wilc_hif_func *ops);
int wilc_cfg80211_register(struct wilc *wilc);
void wilc_deinit_host_int(struct net_device *net);
int wilc_init_host_int(struct net_device *net);
void wilc_wfi_monitor_rx(struct net_device *mon_dev, u8 *buff, u32 size);
void wilc_wfi_deinit_mon_interface(struct wilc *wl, bool rtnl_locked);
struct net_device *wilc_wfi_init_mon_interface(struct wilc *wl,
					       const char *name,
					       struct net_device *real_dev);
void wilc_update_mgmt_frame_registrations(struct wiphy *wiphy,
					  struct wireless_dev *wdev,
					  struct mgmt_frame_regs *upd);
struct wilc_vif *wilc_get_wl_to_vif(struct wilc *wl);
void wlan_deinit_locks(struct wilc *wilc);
#endif
