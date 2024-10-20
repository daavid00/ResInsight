#include "gtest/gtest.h"

#include "RifEclipseRftAddress.h"
#include "RifReaderEclipseRft.h"

#include <vector>

//--------------------------------------------------------------------------------------------------
///
//--------------------------------------------------------------------------------------------------
// TEST(RifReaderEclipseRftTest, TestRifEclipseRftAddress)
TEST( DISABLED_RifReaderEclipseRftTest, TestRifEclipseRftAddress )
{
    QString filename = "C:\\Users\\Rebecca Cox\\Dropbox\\norne\\norne\\NORNE_ATW2013.RFT";

    RifReaderEclipseRft reader( filename );

    std::set<RifEclipseRftAddress> addresses = reader.eclipseRftAddresses();

    /*for (RifEclipseRftAddress address : addresses)
    {
        std::cout << address.wellName() << std::endl;
    }*/

    for ( RifEclipseRftAddress address : addresses )
    {
        std::vector<double> values;
        reader.values( address, &values );
        EXPECT_TRUE( !values.empty() );
    }

    ASSERT_TRUE( !addresses.empty() );

    std::vector<double> values;
    reader.values( *addresses.begin(), &values );
    ASSERT_TRUE( !values.empty() );

    std::cout << "First value: " << values.front() << ", last value: " << values.back() << std::endl;
}
