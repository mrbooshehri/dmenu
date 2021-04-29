#include <X11/Xresource.h>

void
readxresources(void)
{
	XrmInitialize();

	char* xrm;
	if ((xrm = XResourceManagerString(drw->dpy))) {
		char *type;
		XrmDatabase xdb = XrmGetStringDatabase(xrm);
		XrmValue xval;

		if (XrmGetResource(xdb, "dmenu.font", "*", &type, &xval))
			fonts[0] = strdup(xval.addr);
		else
			fonts[0] = strdup(fonts[0]);
		if (XrmGetResource(xdb, "color0", "*", &type, &xval))
			colors[SchemeNorm][ColBg] = strdup(xval.addr);
		else
			colors[SchemeNorm][ColBg] = strdup(colors[SchemeNorm][ColBg]);
		if (XrmGetResource(xdb, "color7", "*", &type, &xval))
			colors[SchemeNorm][ColFg] = strdup(xval.addr);
		else
			colors[SchemeNorm][ColFg] = strdup(colors[SchemeNorm][ColFg]);
		if (XrmGetResource(xdb, "color10", "*", &type, &xval))
			colors[SchemeSel][ColBg] = strdup(xval.addr);
		else
			colors[SchemeSel][ColBg] = strdup(colors[SchemeSel][ColBg]);
		if (XrmGetResource(xdb, "color0", "*", &type, &xval))
			colors[SchemeSel][ColFg] = strdup(xval.addr);
		else
			colors[SchemeSel][ColFg] = strdup(colors[SchemeSel][ColFg]);
		if (XrmGetResource(xdb, "background", "*", &type, &xval))
			colors[SchemeOut][ColBg] = strdup(xval.addr);
		else
			colors[SchemeOut][ColBg] = strdup(colors[SchemeOut][ColBg]);
		if (XrmGetResource(xdb, "foreground", "*", &type, &xval))
			colors[SchemeOut][ColFg] = strdup(xval.addr);
		else
			colors[SchemeOut][ColFg] = strdup(colors[SchemeOut][ColFg]);
		if (XrmGetResource(xdb, "color7", "*", &type, &xval))
			colors[SchemeSelHighlight][ColBg] = strdup(xval.addr);
		else
			colors[SchemeSelHighlight][ColBg] = strdup(colors[SchemeSelHighlight][ColBg]);
		if (XrmGetResource(xdb, "color9", "*", &type, &xval))
			colors[SchemeSelHighlight][ColFg] = strdup(xval.addr);
		else
			colors[SchemeSelHighlight][ColFg] = strdup(colors[SchemeSelHighlight][ColFg]);
		if (XrmGetResource(xdb, "color7", "*", &type, &xval))
			colors[SchemeNormHighlight][ColBg] = strdup(xval.addr);
		else
			colors[SchemeNormHighlight][ColBg] = strdup(colors[SchemeNormHighlight][ColBg]);
		if (XrmGetResource(xdb, "color9", "*", &type, &xval))
			colors[SchemeNormHighlight][ColFg] = strdup(xval.addr);
		else
			colors[SchemeNormHighlight][ColFg] = strdup(colors[SchemeNormHighlight][ColFg]);

		XrmDestroyDatabase(xdb);
	}
}
