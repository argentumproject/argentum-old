#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("argentum://AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("argentum:AWRLWS0d6eEuu0qwsNBxkGxB4RV6FMo90X?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
