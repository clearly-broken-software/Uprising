/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of Uprising
 *
 * Nnjas2 is free software: you can redistribute it and/or modify
 * it under the of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ninjas2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Uprising.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_BRAND "Clearly Broken Software"
#define DISTRHO_PLUGIN_NAME "Uprising"
#define DISTRHO_PLUGIN_URI "https://github.com/clearly-broken-software/uprising"

#define DISTRHO_PLUGIN_IS_SYNTH 0
#define DISTRHO_PLUGIN_HAS_UI 0
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_NUM_INPUTS 0
#define DISTRHO_PLUGIN_NUM_OUTPUTS 2
#define DISTRHO_PLUGIN_WANT_STATE 0
#define DISTRHO_PLUGIN_WANT_FULL_STATE 0
#define DISTRHO_UI_USE_NANOVG 0
#define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 0

#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:InstrumentPlugin"

enum Parameters // exposed to the host
{
    kResetBtn,
    kXval,
    kYval,
    kPosition,
    kEndPoint,
    parameterCount
};

#endif // DISTRHO_PLUGIN_INFO_H_INCLUDED
