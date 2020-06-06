// EnumIterator.py AUTOGENERATED FILE. ** DO NOT EDIT ** Run "python2 Run.py"

#include <algorithm>
#include <stdexcept>

const std::string BLANKSTRING = "";

#include "CmdLineParams.h"

#include "CmdLineParamsEnum.h"

namespace Codec
{
	CodecEnum::EnumData CodecEnum::mSortedByEnum[5 + 1] = {
		CodecEnum::EnumData( bc6h, "bc6h" ),            //
		CodecEnum::EnumData( eac_r11, "eac_r11" ),      //
		CodecEnum::EnumData( etc1, "etc1" ),            //
		CodecEnum::EnumData( etc2_rgb, "etc2_rgb" ),    //
		CodecEnum::EnumData( etc2_rgba, "etc2_rgba" ),  //
		CodecEnum::EnumData( etc2_rgba, "__INVALID" )
	};

	CodecEnum::EnumData CodecEnum::mSortedByString[5 + 1] = {
		CodecEnum::EnumData( bc6h, "bc6h" ),            //
		CodecEnum::EnumData( eac_r11, "eac_r11" ),      //
		CodecEnum::EnumData( etc1, "etc1" ),            //
		CodecEnum::EnumData( etc2_rgb, "etc2_rgb" ),    //
		CodecEnum::EnumData( etc2_rgba, "etc2_rgba" ),  //
		CodecEnum::EnumData( etc2_rgba, "__INVALID" )
	};

	//---------------------------------------------------------------------------------------
	CodecEnum::EnumData::EnumData( Codec _enumValue, const std::string &_enumString ) :
		enumValue( _enumValue ),
		enumString( _enumString )
	{
	}
	//---------------------------------------------------------------------------------------
	struct CodecEnum::OrderByEnum
	{
		bool operator()( const CodecEnum::EnumData &_l, Codec _r ) const { return _l.enumValue < _r; }

		bool operator()( Codec _l, const CodecEnum::EnumData &_r ) const { return _l < _r.enumValue; }

		bool operator()( const CodecEnum::EnumData &_l, int _r ) const { return _l.enumValue < _r; }

		bool operator()( int _l, const CodecEnum::EnumData &_r ) const { return _l < _r.enumValue; }
	};
	//---------------------------------------------------------------------------------------
	struct CodecEnum::OrderByStr
	{
		bool operator()( const CodecEnum::EnumData &_l, const std::string &_r ) const
		{
			return _l.enumString < _r;
		}

		bool operator()( const std::string &_l, const CodecEnum::EnumData &_r ) const
		{
			return _l < _r.enumString;
		}
	};
	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------
	int CodecEnum::minValue() { return mSortedByEnum[0].enumValue; }
	//---------------------------------------------------------------------------------------
	int CodecEnum::maxValue() { return mSortedByEnum[5 - 1].enumValue; }
	//---------------------------------------------------------------------------------------
	size_t CodecEnum::count() { return 5; }
	//---------------------------------------------------------------------------------------
	bool CodecEnum::find( const std::string &strValue, Codec &outValue )
	{
		const EnumData *itor =
			std::lower_bound( &mSortedByString[0], &mSortedByString[5], strValue, OrderByStr() );

		if( itor != &mSortedByString[5] && itor->enumString == strValue )
		{
			outValue = itor->enumValue;
			return true;
		}
		else
		{
			return false;
		}
	}
	//---------------------------------------------------------------------------------------
	Codec CodecEnum::find( const std::string &strValue )
	{
		Codec retVal;
		const bool bFound = find( strValue, retVal );
		if( !bFound )
		{
			throw std::invalid_argument( "String: " + strValue + " is not a valid enum of type Codec" );
		}

		return retVal;
	}

	//---------------------------------------------------------------------------------------
	bool CodecEnum::isValidValue( int value ) { return minValue() >= value && value <= maxValue(); }
	//---------------------------------------------------------------------------------------
	const std::string &CodecEnum::get( Codec value )
	{
		const int idx = value - mSortedByEnum[0].enumValue;
		if( idx >= count() )
			return BLANKSTRING;

		return mSortedByEnum[idx].enumString;
	}
	//---------------------------------------------------------------------------------------
	const std::string &CodecEnum::find( Codec value ) { return get( value ); }
}  // namespace Codec
