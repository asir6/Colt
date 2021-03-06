﻿#region Disclaimer / License
// Copyright (C) 2010, Jackie Ng
// http://trac.osgeo.org/mapguide/wiki/maestro, jumpinjackie@gmail.com
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
#endregion
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using OSGeo.MapGuide.ObjectModels.ApplicationDefinition;
using Maestro.Shared.UI;

namespace Maestro.Editors.Fusion.WidgetEditors
{
    /// <summary>
    /// Base widget editor class
    /// </summary>
    public partial class WidgetEditorBase : UserControl, IWidgetEditor
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public WidgetEditorBase()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Initializes the editor
        /// </summary>
        /// <param name="widget"></param>
        /// <param name="context"></param>
        /// <param name="edsvc"></param>
        public void Setup(IWidget widget, FlexibleLayoutEditorContext context, IEditorService edsvc)
        {
            TextBoxBinder.BindText(txtName, widget, "Name"); //NOXLATE
            TextBoxBinder.BindText(txtType, widget, "Type"); //NOXLATE
            TextBoxBinder.BindText(txtLocation, widget, "Location"); //NOXLATE
        }

        /// <summary>
        /// Gets the underyling Windows Forms control
        /// </summary>
        public Control Content
        {
            get { return this; }
        }
    }
}
