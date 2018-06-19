/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef PINK_DETECTION_TABLES_H
#define PINK_DETECTION_TABLES_H

#include "gui/EventRecorder.h"

namespace Pink {

static const ADGameDescription gameDescriptions[] = {
	// English, Version 1.0
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "223d0114d443904d8949263d512859da", 618203600},
			{"PPTP.BRO", 0, "bbbc78c0525694b32157570e2ec29784", 8945466},
			{"PPTP.EXE", 0, "82460a604723ed5697fc87cddf9dbeed", 594432},
			AD_LISTEND
		},
		Common::EN_ANY,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Finnish
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "32c31829bf7e74a64968dd05f3224ce9", 612549215},
			{"PPTP.BRO", 0, "bbbc78c0525694b32157570e2ec29784", 8945466},
			{"PPTP.EXE", 0, "03481f57d216d368ef218b80c28dd2a2", 599040},
			AD_LISTEND
		},
		Common::FI_FIN,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// French
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "fd641b5735fbe41d14db698ece29d2b1", 607185037},
			{"PPTP.BRO", 0, "634d344ab9aaf7c919ef2d330327c908", 8945466},
			{"PPTP.EXE", 0, "c2f2f717f33a234b257143a9f2baa18d", 598528},
			AD_LISTEND
		},
		Common::FR_FRA,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Hebrew
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "52e2aba46d6cc47225bd5345775eeb59", 616292424},
			{"PPTP.BRO", 0, "9b890f4707b35feb4436bc69d19a5552", 8945466},
			{"PPTP.EXE", 0, "c78b229fa371a0863225f5159b5d28d9", 592384},
			AD_LISTEND
		},
		Common::HE_ISR,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Polish
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "3b987bb529e131b92c3eb912871dedbd", 644839372},
			{"PPTP.BRO", 0, "138a84d0c6ea00066aff488c91cb1973", 8945466},
			{"PPTP.EXE", 0, "409d7dbc33c5cbfb3457468755d33691", 594432},
			AD_LISTEND
		},
		Common::PL_POL,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Portuguese
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "88a498256c4609550cf59497a372b7a3", 642216577},
			{"PPTP.BRO", 0, "083c2fb4a3674c384cbc2884fcf774e2", 8945466},
			{"PPTP.EXE", 0, "6cb9fab3f9b7dc25c3717d657056a149", 598528},
			AD_LISTEND
		},
		Common::PT_BRA,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Russian
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "4802bace9cd89a73eb915a075b230646", 635322616},
			{"PPTP.BRO", 0, "87539dbbb34bafbe223c751a60254505", 8945466},
			{"PPTP.EXE", 0, "739259d239acdc0304f904016e775fb3", 742912},
			AD_LISTEND
		},
		Common::RU_RUS,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Spanish
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "1225f76fe3a60d2ed2321ac92e2c1e79", 633626567},
			{"PPTP.BRO", 0, "af9e0e58ee9046dceda4f55060ebd34c", 20},
			{"PPTP.EXE", 0, "69f0472cda67bc146cbb709da2bc58fe", 595456},
			AD_LISTEND
		},
		Common::ES_ESP,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Swedish
	{
		"peril",
		0,
		{
			{"PPTP.ORB", 0, "eadbc52f4c43b85edb7cc493b4149ba0", 633843917},
			{"PPTP.BRO", 0, "e0e479418f7ace8735d824cfdabe851d", 8945466},
			{"PPTP.EXE", 0, "52db4fa96604a2d2026140a26a5e69e2", 594944},
			AD_LISTEND
		},
		Common::SE_SWE,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// English, Version 1.0
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "f480597a78ab70c2021b4141fe44a512", 503443586},
			{"hpp.exe", 0, "05c321e75dd51e40f00c6d85cf9f2b34", 697856},
			AD_LISTEND
		},
		Common::EN_ANY,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// French
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "d5af74262276f0ffef6605ea0db861d2", 492220293},
			{"hpp.exe", 0, "418f2f126903c51f9979c76c22d03e53", 707072},
			AD_LISTEND
		},
		Common::FR_FRA,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Hebrew
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "518453b73021c31566f084b3e4b8bdbf", 502988485},
			{"hpp.exe", 0, "652a797bf4329834dbdd172749d37996", 642048},
			AD_LISTEND
		},
		Common::HE_ISR,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Polish
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "51fb70412a6a5a6590dcaee842a940ab", 539274161},
			{"hpp.exe", 0, "8ed8d6c53b0792e6d2e55b89bf5cad9a", 697856},
			AD_LISTEND
		},
		Common::PL_POL,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Portuguese
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "149661ec6c35488a300293776a74b460", 526755539},
			{"hpp.exe", 0, "57aefed890deeac3227660f75833acc9", 698880},
			AD_LISTEND
		},
		Common::PT_BRA,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Russian
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "1e5155c2219b3baea599563e02596ce5", 526369062},
			{"hpp.exe", 0, "32a5937f69dfce9f159b7be358cbd008", 699904},
			AD_LISTEND
		},
		Common::RU_RUS,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Spanish
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "68040543f153e494e42efe9fab47b850", 508716126},
			{"hpp.exe", 0, "ce835ddfd7444b2e4a613ca5a82125a4", 699904},
			AD_LISTEND
		},
		Common::ES_ESP,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	// Swedish
	{
		"pokus",
		0,
		{
			{"HPP.orb", 0, "7b7909414d93f847ff0c023a06ae1f7e", 500103742},
			{"hpp.exe", 0, "ba40c8ecfa36f2d21fdd8d8c14d4b09c", 673280},
			AD_LISTEND
		},
		Common::SE_SWE,
		Common::kPlatformWindows,
		ADGF_UNSTABLE | ADGF_DROPPLATFORM,
		GUIO1(GUIO_NONE)
	},

	AD_TABLE_END_MARKER
};

} // End of namespace Pink

#endif