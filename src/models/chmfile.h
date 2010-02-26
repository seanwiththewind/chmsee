/*
 *  copyright (C) 2010 Ji YongGang <jungleji@gmail.com>
 *  Copyright (C) 2009 LI Daobing <lidaobing@gmail.com>
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

#ifndef __CS_CHMFILE_H__
#define __CS_CHMFILE_H__

#include <glib.h>
#include <glib-object.h>

typedef struct _CsChmfile       CsChmfile;
typedef struct _CsChmfileClass  CsChmfileClass;

#define CS_TYPE_CHMFILE         (cs_chmfile_get_type ())
#define CS_CHMFILE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), CS_TYPE_CHMFILE, CsChmfile))
#define CS_CHMFILE_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST    ((k), CS_TYPE_CHMFILE, CsChmfileClass))
#define IS_CS_CHMFILE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), CS_TYPE_CHMFILE))
#define IS_CS_CHMFILE_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE    ((k), CS_TYPE_CHMFILE))
#define CS_CHMFILE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS  ((o), CS_TYPE_CHMFILE, CsChmfileClass))

struct _CsChmfile
{
        GObject      object;
};

struct _CsChmfileClass
{
        GObjectClass parent_class;
};

GType       cs_chmfile_get_type(void);
CsChmfile  *cs_chmfile_new(const gchar *);

CsChmIndex *cs_chmfile_get_index(CsChmfile* self);

const gchar *cs_chmfile_get_filename(CsChmfile *);
const gchar *cs_chmfile_get_bookname(CsChmfile *);
const gchar *cs_chmfile_get_homepage(CsChmfile *);

#endif /* !__CS_CHMFILE_H__ */
