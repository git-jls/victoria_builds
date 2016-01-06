/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]        = "-*-tamsyn-medium-*-*-*-12-*-*-*-*-*-iso8859-*";
static const char* normbgcolor  = "#222222";
static const char* normfgcolor  = "#899CA1";
static const char* selbgcolor   = "#222222";
static const char* selfgcolor   = "#666666";
static const char before[]      = "<";
static const char after[]       = ">";
static const int  tabwidth      = 200;
static const Bool foreground    = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 0;
static Bool npisrelative  = False;

#define SETPROP(p) { \
	.v = (char *[]){ "/bin/sh", "-c", \
		"prop=\"`xwininfo -children -id $1 | grep '^     0x' | sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' | xargs -0 printf %b | dmenu -l 10`\" &&" \
		"xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
		p, winid, NULL \
	} \
}

#define MODKEY ControlMask
static Key keys[] = { \
	/* modifier                     key        function        argument */
	{ MODKEY,             XK_Return, focusonce,      { 0 } },
	{ MODKEY,             XK_Return, spawn,          { .v = (char*[]){ "vimb", "-e", winid, NULL} } },
	{ MODKEY,             XK_x,      spawn,          SETPROP("_TABBED_SELECT_TAB") },
	{ MODKEY,             XK_l,      rotate,         { .i = +1 } },
	{ MODKEY,             XK_Right,  rotate,         { .i = +1 } },
	{ MODKEY,             XK_h,      rotate,         { .i = -1 } },
	{ MODKEY,             XK_Left,   rotate,         { .i = -1 } },
	{ MODKEY,             XK_j,      movetab,        { .i = -1 } },
	{ MODKEY,             XK_k,      movetab,        { .i = +1 } },
	{ MODKEY,             XK_Tab,    rotate,         { .i = 0 } },

	{ MODKEY,             XK_1,      move,           { .i = 0 } },
	{ MODKEY,             XK_2,      move,           { .i = 1 } },
	{ MODKEY,             XK_3,      move,           { .i = 2 } },
	{ MODKEY,             XK_4,      move,           { .i = 3 } },
	{ MODKEY,             XK_5,      move,           { .i = 4 } },
	{ MODKEY,             XK_6,      move,           { .i = 5 } },
	{ MODKEY,             XK_7,      move,           { .i = 6 } },
	{ MODKEY,             XK_8,      move,           { .i = 7 } },
	{ MODKEY,             XK_9,      move,           { .i = 8 } },
	{ MODKEY,             XK_0,      move,           { .i = 9 } },

	{ MODKEY,             XK_q,      killclient,     { 0 } },

	{ 0,                  XK_F11,    fullscreen,     { 0 } },
};

