/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Agave Nerd Font Propo:size=16"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#cdd6f4", "#1e1e2e" },
	[SchemeSel] = { "#1e1e2e", "#89dceb" },
	[SchemeSelHighlight]  = { "#f9e2af", "#005577" },
	[SchemeNormHighlight] = { "#f9e2af", "#181825" },
	[SchemeOut] = { "#000000", "#89dceb" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 25;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
