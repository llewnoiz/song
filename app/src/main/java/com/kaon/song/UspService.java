package com.kaon.song;

import android.app.Service;
import android.app.usage.NetworkStatsManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.Network;
import android.net.NetworkInfo;
import android.os.IBinder;
import android.util.Log;

import androidx.annotation.Nullable;

import java.net.NetworkInterface;

public class UspService extends Service {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public void Start() {
        Thread th1 = new Thread(new Runnable() {
            @Override
            public void run() {
                UspAgentStart();
            }
        });
        th1.run();
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();

        //NetworkStatsManager systemService = (NetworkStatsManager) getSystemService(NETWORK_STATS_SERVICE);
        //ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(CONNECTIVITY_SERVICE);
        //ConnectivityManager.NetworkCallback


    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {

        if(intent != null)
        {
            if(intent.getAction().equals(Intent.ACTION_BOOT_COMPLETED))
            {
                Thread th1 = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        UspAgentStart();
                    }
                });
                th1.run();
            }

        }
        //return super.onStartCommand(intent, flags, startId);
        return START_STICKY;
    }
    public native void UspAgentStart();
    public native void UspAgentStop();
}
