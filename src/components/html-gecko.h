/*
 *  Copyright (C) 2010 Ji YongGang <jungleji@gmail.com>
 *
 *  ChmSee is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.

 *  ChmSee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with ChmSee; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#ifndef __CS_HTML_GECKO_H__
#define __CS_HTML_GECKO_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include <gtkmozembed.h>

G_BEGIN_DECLS

#define CS_TYPE_HTML_GECKO         (cs_html_gecko_get_type())
#define CS_HTML_GECKO(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), CS_TYPE_HTML_GECKO, CsHtmlGecko))
#define CS_HTML_GECKO_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST    ((k), CS_TYPE_HTML_GECKO, CsHtmlGeckoClass))
#define IS_CS_HTML_GECKO(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), CS_TYPE_HTML_GECKO))
#define IS_CS_HTML_GECKO_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE    ((k), CS_TYPE_HTML_GECKO))

typedef struct _CsHtmlGecko        CsHtmlGecko;
typedef struct _CsHtmlGeckoClass   CsHtmlGeckoClass;

struct _CsHtmlGecko {
        GObject      parent;
        GtkMozEmbed *gecko;
};

struct _CsHtmlGeckoClass {
        GObjectClass parent_class;
};

GType        cs_html_gecko_get_type(void);
CsHtmlGecko *cs_html_gecko_new(void);

GtkWidget   *cs_html_gecko_get_widget(CsHtmlGecko *);
void         cs_html_gecko_open_uri(CsHtmlGecko *, const gchar *);

gchar       *cs_html_gecko_get_title(CsHtmlGecko *);
gchar       *cs_html_gecko_get_location(CsHtmlGecko *);

gboolean     cs_html_gecko_can_go_back(CsHtmlGecko *);
gboolean     cs_html_gecko_can_go_forward(CsHtmlGecko *);
void         cs_html_gecko_go_back(CsHtmlGecko *);
void         cs_html_gecko_go_forward(CsHtmlGecko *);

void         cs_html_gecko_copy_selection(CsHtmlGecko *);
void         cs_html_gecko_select_all(CsHtmlGecko *);

void         cs_html_gecko_increase_size(CsHtmlGecko *);
void         cs_html_gecko_decrease_size(CsHtmlGecko *);
void         cs_html_gecko_reset_size(CsHtmlGecko *);

void         cs_html_gecko_clear(CsHtmlGecko *);

gboolean     cs_html_gecko_init_system(void);
void         cs_html_gecko_shutdown_system(void);

void         cs_html_gecko_set_default_lang(gint);
void         cs_html_gecko_set_variable_font(const gchar *);
void         cs_html_gecko_set_fixed_font(const gchar *);

G_END_DECLS

#endif /* !__CS_HTML_GECKO_H__ */
