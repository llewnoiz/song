package com.kaon.song;

import android.content.Context;
import android.net.EthernetManager;
import android.net.IpConfiguration;
import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    EthernetManager mEthernetManager;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


//        Log.d("UspReceiver","1111111111111111111111111");
//        mEthernetManager = (EthernetManager) getSystemService(Context.ETHERNET_SERVICE);
//        Log.d("UspReceiver","11111111111111111111111112");
//        IpConfiguration ipConfig =mEthernetManager.getConfiguration();
//        IpConfiguration.IpAssignment ip = ipConfig.getIpAssignment();
//        Log.d("UspReceiver","IP ASSGINED : "+ ip.toString());
//        Log.d("UspReceiver","11111111111111111111111113");
//
//        Thread th1 = new Thread(new Runnable() {
//            @Override
//            public void run() {
//                //Log.d("ANDROID_TR369", getSerial());
//                new UspService().Start();
//            }
//        });
//        th1.run();
    }


}
