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
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Maestro.Editors.Generic.XmlEditor.AutoCompletion
{
    /// <summary>
    ///   A collection that stores <see cref='QualifiedName'/> objects.
    /// </summary>
    [Serializable()]
    internal class QualifiedNameCollection : CollectionBase
    {

        /// <summary>
        ///   Initializes a new instance of <see cref='QualifiedNameCollection'/>.
        /// </summary>
        public QualifiedNameCollection()
        {
        }

        /// <summary>
        ///   Initializes a new instance of <see cref='QualifiedNameCollection'/> based on another <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <param name='val'>
        ///   A <see cref='QualifiedNameCollection'/> from which the contents are copied
        /// </param>
        public QualifiedNameCollection(QualifiedNameCollection val)
        {
            this.AddRange(val);
        }

        /// <summary>
        ///   Initializes a new instance of <see cref='QualifiedNameCollection'/> containing any array of <see cref='QualifiedName'/> objects.
        /// </summary>
        /// <param name='val'>
        ///       A array of <see cref='QualifiedName'/> objects with which to intialize the collection
        /// </param>
        public QualifiedNameCollection(QualifiedName[] val)
        {
            this.AddRange(val);
        }

        /// <summary>
        ///   Represents the entry at the specified index of the <see cref='QualifiedName'/>.
        /// </summary>
        /// <param name='index'>The zero-based index of the entry to locate in the collection.</param>
        /// <value>The entry at the specified index of the collection.</value>
        /// <exception cref='ArgumentOutOfRangeException'><paramref name='index'/> is outside the valid range of indexes for the collection.</exception>
        public QualifiedName this[int index]
        {
            get
            {
                return ((QualifiedName)(List[index]));
            }
            set
            {
                List[index] = value;
            }
        }

        /// <summary>
        ///   Adds a <see cref='QualifiedName'/> with the specified value to the 
        ///   <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <param name='val'>The <see cref='QualifiedName'/> to add.</param>
        /// <returns>The index at which the new element was inserted.</returns>
        public int Add(QualifiedName val)
        {
            return List.Add(val);
        }

        /// <summary>
        ///   Copies the elements of an array to the end of the <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <param name='val'>
        ///    An array of type <see cref='QualifiedName'/> containing the objects to add to the collection.
        /// </param>
        /// <seealso cref='QualifiedNameCollection.Add'/>
        public void AddRange(QualifiedName[] val)
        {
            for (int i = 0; i < val.Length; i++)
            {
                this.Add(val[i]);
            }
        }

        /// <summary>
        ///   Adds the contents of another <see cref='QualifiedNameCollection'/> to the end of the collection.
        /// </summary>
        /// <param name='val'>
        ///    A <see cref='QualifiedNameCollection'/> containing the objects to add to the collection.
        /// </param>
        /// <seealso cref='QualifiedNameCollection.Add'/>
        public void AddRange(QualifiedNameCollection val)
        {
            for (int i = 0; i < val.Count; i++)
            {
                this.Add(val[i]);
            }
        }

        /// <summary>
        ///   Gets a value indicating whether the 
        ///    <see cref='QualifiedNameCollection'/> contains the specified <see cref='QualifiedName'/>.
        /// </summary>
        /// <param name='val'>The <see cref='QualifiedName'/> to locate.</param>
        /// <returns>
        /// <see langword='true'/> if the <see cref='QualifiedName'/> is contained in the collection; 
        ///   otherwise, <see langword='false'/>.
        /// </returns>
        /// <seealso cref='QualifiedNameCollection.IndexOf'/>
        public bool Contains(QualifiedName val)
        {
            return List.Contains(val);
        }

        /// <summary>
        ///   Copies the <see cref='QualifiedNameCollection'/> values to a one-dimensional <see cref='Array'/> instance at the 
        ///    specified index.
        /// </summary>
        /// <param name='array'>The one-dimensional <see cref='Array'/> that is the destination of the values copied from <see cref='QualifiedNameCollection'/>.</param>
        /// <param name='index'>The index in <paramref name='array'/> where copying begins.</param>
        /// <exception cref='ArgumentException'>
        ///   <para><paramref name='array'/> is multidimensional.</para>
        ///   <para>-or-</para>
        ///   <para>The number of elements in the <see cref='QualifiedNameCollection'/> is greater than
        ///         the available space between <paramref name='index'/> and the end of
        ///         <paramref name='array'/>.</para>
        /// </exception>
        /// <exception cref='ArgumentNullException'><paramref name='array'/> is <see langword='null'/>. </exception>
        /// <exception cref='ArgumentOutOfRangeException'><paramref name='index'/> is less than <paramref name='array'/>'s lowbound. </exception>
        /// <seealso cref='Array'/>
        public void CopyTo(QualifiedName[] array, int index)
        {
            List.CopyTo(array, index);
        }

        /// <summary>
        ///    Returns the index of a <see cref='QualifiedName'/> in 
        ///       the <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <param name='val'>The <see cref='QualifiedName'/> to locate.</param>
        /// <returns>
        ///   The index of the <see cref='QualifiedName'/> of <paramref name='val'/> in the 
        ///   <see cref='QualifiedNameCollection'/>, if found; otherwise, -1.
        /// </returns>
        /// <seealso cref='QualifiedNameCollection.Contains'/>
        public int IndexOf(QualifiedName val)
        {
            return List.IndexOf(val);
        }

        /// <summary>
        ///   Inserts a <see cref='QualifiedName'/> into the <see cref='QualifiedNameCollection'/> at the specified index.
        /// </summary>
        /// <param name='index'>The zero-based index where <paramref name='val'/> should be inserted.</param>
        /// <param name='val'>The <see cref='QualifiedName'/> to insert.</param>
        /// <seealso cref='QualifiedNameCollection.Add'/>
        public void Insert(int index, QualifiedName val)
        {
            List.Insert(index, val);
        }

        /// <summary>
        ///  Returns an enumerator that can iterate through the <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <seealso cref='IEnumerator'/>
        public new QualifiedNameEnumerator GetEnumerator()
        {
            return new QualifiedNameEnumerator(this);
        }

        /// <summary>
        ///   Removes a specific <see cref='QualifiedName'/> from the <see cref='QualifiedNameCollection'/>.
        /// </summary>
        /// <param name='val'>The <see cref='QualifiedName'/> to remove from the <see cref='QualifiedNameCollection'/>.</param>
        /// <exception cref='ArgumentException'><paramref name='val'/> is not found in the Collection.</exception>
        public void Remove(QualifiedName val)
        {
            List.Remove(val);
        }

        /// <summary>
        /// Removes the last item in this collection.
        /// </summary>
        public void RemoveLast()
        {
            if (Count > 0)
            {
                RemoveAt(Count - 1);
            }
        }

        /// <summary>
        /// Removes the first item in the collection.
        /// </summary>
        public void RemoveFirst()
        {
            if (Count > 0)
            {
                RemoveAt(0);
            }
        }

        /// <summary>
        /// Gets the namespace prefix of the last item.
        /// </summary>
        public string LastPrefix
        {
            get
            {
                if (Count > 0)
                {
                    QualifiedName name = this[Count - 1];
                    return name.Prefix;
                }
                return String.Empty;
            }
        }

        /// <summary>
        ///   Enumerator that can iterate through a QualifiedNameCollection.
        /// </summary>
        /// <seealso cref='IEnumerator'/>
        /// <seealso cref='QualifiedNameCollection'/>
        /// <seealso cref='QualifiedName'/>
        public class QualifiedNameEnumerator : IEnumerator
        {
            IEnumerator baseEnumerator;
            IEnumerable temp;

            /// <summary>
            ///   Initializes a new instance of <see cref='QualifiedNameEnumerator'/>.
            /// </summary>
            public QualifiedNameEnumerator(QualifiedNameCollection mappings)
            {
                this.temp = ((IEnumerable)(mappings));
                this.baseEnumerator = temp.GetEnumerator();
            }

            /// <summary>
            ///   Gets the current <see cref='QualifiedName'/> in the <seealso cref='QualifiedNameCollection'/>.
            /// </summary>
            public QualifiedName Current
            {
                get
                {
                    return ((QualifiedName)(baseEnumerator.Current));
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
            ///   Advances the enumerator to the next <see cref='QualifiedName'/> of the <see cref='QualifiedNameCollection'/>.
            /// </summary>
            public bool MoveNext()
            {
                return baseEnumerator.MoveNext();
            }

            /// <summary>
            ///   Sets the enumerator to its initial position, which is before the first element in the <see cref='QualifiedNameCollection'/>.
            /// </summary>
            public void Reset()
            {
                baseEnumerator.Reset();
            }
        }
    }
}
