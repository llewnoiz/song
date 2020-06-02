// IUspContorllerInterface.aidl
package com.kaon.song;

// Declare any non-default types here with import statements

interface IUspContorllerInterface {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,
            double aDouble, String aString);

    //void registerCallback(in IUspControllerCallback cb);
    //void unregisterCallback(in IUspControllerCallback cb);
    //void sendMessage(int what, in Bundle bundle);
}
