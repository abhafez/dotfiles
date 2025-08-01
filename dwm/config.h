/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* systray */
static const int showsystray        = 1;        /* 0 means no systray */
static const int systraypinning    = 0;        /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int systrayonleft     = 0;        /* 0: systray in the right corner, >0: systray on left of status text */
static const int systrayspacing    = 4;        /* systray spacing */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Blogger Sans Medium:size=18:antialias=true:autohint=true","Agave Nerd Font Propo:size=20:antialias=true:autohint=true", "Noto Sans Arabic:size=18:antialias=true:autohint=true", "Noto Color Emoji:size=18:antialias=true:autohint=true" };
static const char dmenufont[]       = "Blogger Sans Medium:size=18:antialias=true:autohint=true";
static const char col_gray1[]       = "#1e1e2e";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

#include "themes/catppuccin.h"

static const char *colors[][3]      = {
    /*                     fg       bg      border */
    [SchemeNorm]       = { gray3,   black,  gray2 },
    [SchemeSel]        = { gray4,   purple,   purple  },
    // [SchemeTitle]      = { white,   black,  black }, // active window title
    // [TabSel]           = { blue,    gray2,  black },
    // [TabNorm]          = { gray3,   black,  black },
    // [SchemeTag]        = { gray3,   black,  black },
    // [SchemeTag1]       = { blue,    black,  black },
    // [SchemeTag2]       = { red,     black,  black },
    // [SchemeTag3]       = { orange,  black,  black },
    // [SchemeTag4]       = { green,   black,  black },
    // [SchemeTag5]       = { pink,    black,  black },
    // [SchemeLayout]     = { green,   black,  black },
    // [SchemeBtnPrev]    = { green,   black,  black },
    // [SchemeBtnNext]    = { yellow,  black,  black },
    // [SchemeBtnClose]   = { red,     black,  black },
};

/* tagging */
static const char *tags[] = { "", "󰅪", "", "", "󰧮",  "󱘶", "󱨴", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/*		class				   instance		    title       tags mask     isfloating   monitor */
	{ "copyq",     NULL,       NULL,       0,            1,           -1 },
	{ "peek",	   NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰝘",      		tile },    /* first entry is default */
	{ "",      		NULL },    /* no layout function means floating behavior */
	{ "[M]",      		monocle },
	{ "",        		spiral },
	{ "[\\]",      	dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont  };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *stcmd[]  = { "st", NULL };

#include "movestack.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_s,      spawn,          {.v = stcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ ALTKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask|ControlMask, XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask|ControlMask, XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Tab,	  viewnext,       {0} },
	{ MODKEY,                       XK_Right,  viewnext,       {0} },
	{ MODKEY,                       XK_Left,   viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(								XK_1,                      0)
	TAGKEYS(								XK_2,                      1)
	TAGKEYS(								XK_3,                      2)
	TAGKEYS(								XK_4,                      3)
	TAGKEYS(								XK_5,                      4)
	TAGKEYS(								XK_6,                      5)
	TAGKEYS(								XK_7,                      6)
	TAGKEYS(								XK_8,                      7)
	TAGKEYS(								XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

