﻿#region Disclaimer / License
// Copyright (C) 2013, Jackie Ng
// http://trac.osgeo.org/mapguide/wiki/maestro, jumpinjackie@gmail.com
// 
// Original code from SharpDevelop 3.2.1 licensed under the same terms (LGPL 2.1)
// Copyright 2002-2010 by
//
//  AlphaSierraPapa, Christoph Wille
//  Vordernberger Strasse 27/8
//  A-8700 Leoben
//  Austria
//
//  email: office@alphasierrapapa.com
//  court of jurisdiction: Landesgericht Leoben
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
using ICSharpCode.TextEditor.Gui.CompletionWindow;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Maestro.Editors.Generic.XmlEditor.AutoCompletion
{
    /// <summary>
    ///   A collection that stores <see cref='XmlCompletionData'/> objects.
    /// </summary>
    [Serializable()]
    internal class XmlCompletionDataCollection : CollectionBase
    {

        /// <summary>
        ///   Initializes a new instance of <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        public XmlCompletionDataCollection()
        {
        }

        /// <summary>
        ///   Initializes a new instance of <see cref='XmlCompletionDataCollection'/> based on another <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <param name='val'>
        ///   A <see cref='XmlCompletionDataCollection'/> from which the contents are copied
        /// </param>
        public XmlCompletionDataCollection(XmlCompletionDataCollection val)
        {
            this.AddRange(val);
        }

        /// <summary>
        ///   Initializes a new instance of <see cref='XmlCompletionDataCollection'/> containing any array of <see cref='XmlCompletionData'/> objects.
        /// </summary>
        /// <param name='val'>
        ///       A array of <see cref='XmlCompletionData'/> objects with which to intialize the collection
        /// </param>
        public XmlCompletionDataCollection(XmlCompletionData[] val)
        {
            this.AddRange(val);
        }

        /// <summary>
        ///   Represents the entry at the specified index of the <see cref='XmlCompletionData'/>.
        /// </summary>
        /// <param name='index'>The zero-based index of the entry to locate in the collection.</param>
        /// <value>The entry at the specified index of the collection.</value>
        /// <exception cref='ArgumentOutOfRangeException'><paramref name='index'/> is outside the valid range of indexes for the collection.</exception>
        public XmlCompletionData this[int index]
        {
            get
            {
                return ((XmlCompletionData)(List[index]));
            }
            set
            {
                List[index] = value;
            }
        }

        /// <summary>
        ///   Adds a <see cref='XmlCompletionData'/> with the specified value to the 
        ///   <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <remarks>
        /// If the completion data already exists in the collection it is not added.
        /// </remarks>
        /// <param name='val'>The <see cref='XmlCompletionData'/> to add.</param>
        /// <returns>The index at which the new element was inserted.</returns>
        public int Add(XmlCompletionData val)
        {
            int index = -1;
            if (!Contains(val))
            {
                index = List.Add(val);
            }
            return index;
        }

        /// <summary>
        ///   Copies the elements of an array to the end of the <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <param name='val'>
        ///    An array of type <see cref='XmlCompletionData'/> containing the objects to add to the collection.
        /// </param>
        /// <seealso cref='XmlCompletionDataCollection.Add'/>
        public void AddRange(XmlCompletionData[] val)
        {
            for (int i = 0; i < val.Length; i++)
            {
                this.Add(val[i]);
            }
        }

        /// <summary>
        ///   Adds the contents of another <see cref='XmlCompletionDataCollection'/> to the end of the collection.
        /// </summary>
        /// <param name='val'>
        ///    A <see cref='XmlCompletionDataCollection'/> containing the objects to add to the collection.
        /// </param>
        /// <seealso cref='XmlCompletionDataCollection.Add'/>
        public void AddRange(XmlCompletionDataCollection val)
        {
            for (int i = 0; i < val.Count; i++)
            {
                this.Add(val[i]);
            }
        }

        /// <summary>
        ///   Gets a value indicating whether the 
        ///    <see cref='XmlCompletionDataCollection'/> contains the specified <see cref='XmlCompletionData'/>.
        /// </summary>
        /// <param name='val'>The <see cref='XmlCompletionData'/> to locate.</param>
        /// <returns>
        /// <see langword='true'/> if the <see cref='XmlCompletionData'/> is contained in the collection; 
        ///   otherwise, <see langword='false'/>.
        /// </returns>
        /// <seealso cref='XmlCompletionDataCollection.IndexOf'/>
        public bool Contains(XmlCompletionData val)
        {
            if (val.Text != null)
            {
                if (val.Text.Length > 0)
                {
                    return Contains(val.Text);
                }
            }
            return false;
        }

        public bool Contains(string name)
        {
            bool contains = false;

            foreach (XmlCompletionData data in this)
            {
                if (data.Text != null)
                {
                    if (data.Text.Length > 0)
                    {
                        if (data.Text == name)
                        {
                            contains = true;
                            break;
                        }
                    }
                }
            }

            return contains;
        }

        /// <summary>
        ///   Copies the <see cref='XmlCompletionDataCollection'/> values to a one-dimensional <see cref='Array'/> instance at the 
        ///    specified index.
        /// </summary>
        /// <param name='array'>The one-dimensional <see cref='Array'/> that is the destination of the values copied from <see cref='XmlCompletionDataCollection'/>.</param>
        /// <param name='index'>The index in <paramref name='array'/> where copying begins.</param>
        /// <exception cref='ArgumentException'>
        ///   <para><paramref name='array'/> is multidimensional.</para>
        ///   <para>-or-</para>
        ///   <para>The number of elements in the <see cref='XmlCompletionDataCollection'/> is greater than
        ///         the available space between <paramref name='index'/> and the end of
        ///         <paramref name='array'/>.</para>
        /// </exception>
        /// <exception cref='ArgumentNullException'><paramref name='array'/> is <see langword='null'/>. </exception>
        /// <exception cref='ArgumentOutOfRangeException'><paramref name='index'/> is less than <paramref name='array'/>'s lowbound. </exception>
        /// <seealso cref='Array'/>
        public void CopyTo(XmlCompletionData[] array, int index)
        {
            List.CopyTo(array, index);
        }

        /// <summary>
        ///   Copies the <see cref='XmlCompletionDataCollection'/> values to a one-dimensional <see cref='Array'/> instance at the 
        ///    specified index.
        /// </summary>
        public void CopyTo(ICompletionData[] array, int index)
        {
            List.CopyTo(array, index);
        }

        /// <summary>
        ///    Returns the index of a <see cref='XmlCompletionData'/> in 
        ///       the <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <param name='val'>The <see cref='XmlCompletionData'/> to locate.</param>
        /// <returns>
        ///   The index of the <see cref='XmlCompletionData'/> of <paramref name='val'/> in the 
        ///   <see cref='XmlCompletionDataCollection'/>, if found; otherwise, -1.
        /// </returns>
        public int IndexOf(XmlCompletionData val)
        {
            return List.IndexOf(val);
        }

        /// <summary>
        ///   Inserts a <see cref='XmlCompletionData'/> into the <see cref='XmlCompletionDataCollection'/> at the specified index.
        /// </summary>
        /// <param name='index'>The zero-based index where <paramref name='val'/> should be inserted.</param>
        /// <param name='val'>The <see cref='XmlCompletionData'/> to insert.</param>
        /// <seealso cref='XmlCompletionDataCollection.Add'/>
        public void Insert(int index, XmlCompletionData val)
        {
            List.Insert(index, val);
        }

        /// <summary>
        /// Returns an array of <see cref="ICompletionData"/> items.
        /// </summary>
        /// <returns></returns>
        public ICompletionData[] ToArray()
        {
            ICompletionData[] data = new ICompletionData[Count];
            CopyTo(data, 0);
            return data;
        }

        /// <summary>
        ///  Returns an enumerator that can iterate through the <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <seealso cref='IEnumerator'/>
        public new XmlCompletionDataEnumerator GetEnumerator()
        {
            return new XmlCompletionDataEnumerator(this);
        }

        /// <summary>
        ///   Removes a specific <see cref='XmlCompletionData'/> from the <see cref='XmlCompletionDataCollection'/>.
        /// </summary>
        /// <param name='val'>The <see cref='XmlCompletionData'/> to remove from the <see cref='XmlCompletionDataCollection'/>.</param>
        /// <exception cref='ArgumentException'><paramref name='val'/> is not found in the Collection.</exception>
        public void Remove(XmlCompletionData val)
        {
            List.Remove(val);
        }

        /// <summary>
        ///   Enumerator that can iterate through a XmlCompletionDataCollection.
        /// </summary>
        /// <seealso cref='IEnumerator'/>
        /// <seealso cref='XmlCompletionDataCollection'/>
        /// <seealso cref='XmlCompletionData'/>
        public class XmlCompletionDataEnumerator : IEnumerator
        {
            IEnumerator baseEnumerator;
            IEnumerable temp;

            /// <summary>
            ///   Initializes a new instance of <see cref='XmlCompletionDataEnumerator'/>.
            /// </summary>
            public XmlCompletionDataEnumerator(XmlCompletionDataCollection mappings)
            {
                this.temp = ((IEnumerable)(mappings));
                this.baseEnumerator = temp.GetEnumerator();
            }

            /// <summary>
            ///   Gets the current <see cref='XmlCompletionData'/> in the <seealso cref='XmlCompletionDataCollection'/>.
            /// </summary>
            public XmlCompletionData Current
            {
                get
                {
                    return ((XmlCompletionData)(baseEnumerator.Current));
                }
            }

            object IEnumerator.Current
            {
                get
                {
                    return baseEnumerator.Current;
                }
            }

            /// <summary>
            ///   Advances the enumerator to the next <see cref='XmlCompletionData'/> of the <see cref='XmlCompletionDataCollection'/>.
            /// </summary>
            public bool MoveNext()
            {
                return baseEnumerator.MoveNext();
            }

            /// <summary>
            ///   Sets the enumerator to its initial position, which is before the first element in the <see cref='XmlCompletionDataCollection'/>.
            /// </summary>
            public void Reset()
            {
                baseEnumerator.Reset();
            }
        }
    }
}
