package com.kaon.song;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.EthernetManager;
import android.net.IpConfiguration;
import android.util.Log;

public class   UspReceiver extends BroadcastReceiver {
    EthernetManager mEthernetManager;
    @Override
    public void onReceive(Context context, Intent intent) {
        try {

//            Log.d("UspReceiver","1111111111111111111111111");
//            mEthernetManager = (EthernetManager) context.getSystemService(Context.ETHERNET_SERVICE);
//            Log.d("UspReceiver","11111111111111111111111112");
//            IpConfiguration ipConfig =mEthernetManager.getConfiguration();
//            IpConfiguration.IpAssignment ip = ipConfig.getIpAssignment();
//            //Log.d("UspReceiver","IP ASSGINED : "+ ip.toString());
//            Log.d("UspReceiver","11111111111111111111111113");

            if(intent.getAction().equals(Intent.ACTION_BOOT_COMPLETED))
            {
                Intent mIntent=  new Intent(context.getApplicationContext(), UspService.class);
                context.getApplicationContext().startService(mIntent);
            }
        }
        catch (Exception e)
        {

        }

    }
}
