/*

Imebra 2011 build 2013-09-04_11-02-26

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013 by Paolo Brandoli/Binarno s.p.
All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 support available at http://imebra.com

After you buy the commercial support then you can use Imebra according
 to the terms described in the Imebra Commercial License Version 1.
A copy of the Imebra Commercial License Version 1 is available in the
 documentation pages.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file charsetConversionIconv.h
    \brief Declaration of the class used to convert a string between different
            charsets using the Iconv library.

The class hides the platform specific implementations and supplies a common
 interface for the charsets translations.

*/

#if !defined(imebraCharsetConversionIconv_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_)
#define imebraCharsetConversionIconv_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_

#include "charsetConversion.h"

#include <iconv.h>
#include <errno.h>

///////////////////////////////////////////////////////////
//
// Everything is in the namespace puntoexe
//
///////////////////////////////////////////////////////////
namespace puntoexe
{

class charsetConversionIconv: public charsetConversion
{
public:
    charsetConversionIconv();
    virtual ~charsetConversionIconv();

    virtual void initialize(const int requestedTable);

    virtual std::string fromUnicode(const std::wstring& unicodeString) const;

    virtual std::wstring toUnicode(const std::string& asciiString) const;

protected:
    virtual void close();

	int findTable(const std::string& tableName) const;

	std::string m_isoCharset;

#if defined(PUNTOEXE_WINDOWS)
    std::string myIconv(iconv_t context, const char* inputString, size_t inputStringLengthBytes) const;
#else
    std::string myIconv(iconv_t context, char* inputString, size_t inputStringLengthBytes) const;
#endif
    iconv_t m_iconvToUnicode;
	iconv_t m_iconvFromUnicode;
};

} // namespace puntoexe

#endif // !defined(imebraCharsetConversionIconv_3146DA5A_5276_4804_B9AB_A3D54C6B123A__INCLUDED_)
