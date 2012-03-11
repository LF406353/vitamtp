//
//  test.c
//  VitaMTP
//
//  Created by Yifan Lu on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vitamtp.h>

unsigned char data[] = {
    0xCC, 0x00, 0x00, 0x00, 0x3C, 0x3F, 0x78, 0x6D, 0x6C, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x31, 0x2E, 0x30, 0x22, 0x20, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x3D, 0x22, 0x55, 0x54, 0x46, 0x2D, 0x38, 0x22, 0x3F, 0x3E, 0x0A, 0x3C, 0x69, 0x6E, 0x69, 0x74, 0x69, 0x61, 0x74, 0x6F, 0x72, 0x49, 0x6E, 0x66, 0x6F, 0x20, 0x70, 0x6C, 0x61, 0x74, 0x66, 0x6F, 0x72, 0x6D, 0x54, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x50, 0x43, 0x22, 0x20, 0x70, 0x6C, 0x61, 0x74, 0x66, 0x6F, 0x72, 0x6D, 0x53, 0x75, 0x62, 0x74, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x4D, 0x61, 0x63, 0x22, 0x20, 0x6F, 0x73, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x31, 0x30, 0x2E, 0x37, 0x22, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x31, 0x2E, 0x31, 0x30, 0x2E, 0x34, 0x30, 0x38, 0x36, 0x2E, 0x37, 0x38, 0x22, 0x20, 0x70, 0x72, 0x6F, 0x74, 0x6F, 0x63, 0x6F, 0x6C, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x32, 0x30, 0x30, 0x30, 0x31, 0x30, 0x22, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x79, 0x69, 0x66, 0x61, 0x6E, 0x73, 0x2D, 0x69, 0x6D, 0x61, 0x63, 0x22, 0x20, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x54, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x35, 0x22, 0x20, 0x2F, 0x3E, 0x0A, 0x00
};

unsigned char data2[] = {
    0xC2, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3F, 0x78, 0x6D, 0x6C, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x31, 0x2E, 0x30, 0x22, 0x20, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x3D, 0x22, 0x55, 0x54, 0x46, 0x2D, 0x38, 0x22, 0x3F, 0x3E, 0x0A, 0x3C, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x64, 0x61, 0x74, 0x61, 0x5F, 0x6C, 0x69, 0x73, 0x74, 0x3E, 0x0A, 0x3C, 0x72, 0x65, 0x67, 0x69, 0x6F, 0x6E, 0x20, 0x69, 0x64, 0x3D, 0x22, 0x75, 0x73, 0x22, 0x3E, 0x0A, 0x3C, 0x6E, 0x70, 0x20, 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x36, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x31, 0x5F, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x36, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x32, 0x5F, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x36, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x6D, 0x61, 0x70, 0x3D, 0x22, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x2F, 0x3E, 0x0A, 0x3C, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x36, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x6C, 0x61, 0x62, 0x65, 0x6C, 0x3D, 0x22, 0x31, 0x2E, 0x36, 0x30, 0x22, 0x3E, 0x0A, 0x3C, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x64, 0x61, 0x74, 0x61, 0x20, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x74, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x66, 0x75, 0x6C, 0x6C, 0x22, 0x3E, 0x0A, 0x3C, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x20, 0x73, 0x69, 0x7A, 0x65, 0x3D, 0x22, 0x39, 0x38, 0x36, 0x34, 0x37, 0x30, 0x34, 0x30, 0x22, 0x3E, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x64, 0x75, 0x73, 0x30, 0x31, 0x2E, 0x70, 0x73, 0x70, 0x32, 0x2E, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2E, 0x70, 0x6C, 0x61, 0x79, 0x73, 0x74, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x6E, 0x65, 0x74, 0x2F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2F, 0x70, 0x73, 0x70, 0x32, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x2F, 0x32, 0x30, 0x31, 0x32, 0x5F, 0x30, 0x32, 0x30, 0x36, 0x2F, 0x72, 0x65, 0x6C, 0x5F, 0x35, 0x65, 0x39, 0x63, 0x39, 0x62, 0x63, 0x34, 0x66, 0x34, 0x33, 0x34, 0x64, 0x62, 0x31, 0x34, 0x30, 0x31, 0x64, 0x33, 0x30, 0x65, 0x63, 0x34, 0x31, 0x63, 0x31, 0x37, 0x34, 0x61, 0x62, 0x39, 0x2F, 0x50, 0x53, 0x50, 0x32, 0x55, 0x50, 0x44, 0x41, 0x54, 0x2E, 0x50, 0x55, 0x50, 0x3F, 0x64, 0x65, 0x73, 0x74, 0x3D, 0x75, 0x73, 0x3C, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x3E, 0x0A, 0x3C, 0x2F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x64, 0x61, 0x74, 0x61, 0x3E, 0x0A, 0x3C, 0x2F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3E, 0x0A, 0x3C, 0x72, 0x65, 0x63, 0x6F, 0x76, 0x65, 0x72, 0x79, 0x20, 0x73, 0x70, 0x6B, 0x67, 0x5F, 0x74, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x64, 0x61, 0x74, 0x61, 0x22, 0x3E, 0x0A, 0x3C, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x20, 0x73, 0x70, 0x6B, 0x67, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x30, 0x30, 0x30, 0x2E, 0x30, 0x31, 0x30, 0x22, 0x20, 0x73, 0x69, 0x7A, 0x65, 0x3D, 0x22, 0x35, 0x36, 0x38, 0x32, 0x31, 0x32, 0x34, 0x38, 0x22, 0x3E, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x64, 0x75, 0x73, 0x30, 0x31, 0x2E, 0x70, 0x73, 0x70, 0x32, 0x2E, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2E, 0x70, 0x6C, 0x61, 0x79, 0x73, 0x74, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x6E, 0x65, 0x74, 0x2F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2F, 0x70, 0x73, 0x70, 0x32, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x2F, 0x32, 0x30, 0x31, 0x32, 0x5F, 0x30, 0x32, 0x30, 0x36, 0x2F, 0x73, 0x64, 0x5F, 0x34, 0x39, 0x32, 0x39, 0x39, 0x65, 0x39, 0x34, 0x65, 0x62, 0x63, 0x37, 0x63, 0x30, 0x34, 0x30, 0x62, 0x36, 0x65, 0x30, 0x61, 0x32, 0x64, 0x32, 0x61, 0x37, 0x66, 0x36, 0x64, 0x64, 0x63, 0x63, 0x2F, 0x50, 0x53, 0x50, 0x32, 0x55, 0x50, 0x44, 0x41, 0x54, 0x2E, 0x50, 0x55, 0x50, 0x3F, 0x64, 0x65, 0x73, 0x74, 0x3D, 0x75, 0x73, 0x3C, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x3E, 0x0A, 0x3C, 0x2F, 0x72, 0x65, 0x63, 0x6F, 0x76, 0x65, 0x72, 0x79, 0x3E, 0x0A, 0x3C, 0x72, 0x65, 0x63, 0x6F, 0x76, 0x65, 0x72, 0x79, 0x20, 0x73, 0x70, 0x6B, 0x67, 0x5F, 0x74, 0x79, 0x70, 0x65, 0x3D, 0x22, 0x70, 0x72, 0x65, 0x69, 0x6E, 0x73, 0x74, 0x22, 0x3E, 0x0A, 0x3C, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x20, 0x73, 0x70, 0x6B, 0x67, 0x5F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x30, 0x31, 0x2E, 0x30, 0x30, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x22, 0x20, 0x73, 0x69, 0x7A, 0x65, 0x3D, 0x22, 0x31, 0x32, 0x38, 0x38, 0x34, 0x31, 0x32, 0x31, 0x36, 0x22, 0x3E, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x64, 0x75, 0x73, 0x30, 0x31, 0x2E, 0x70, 0x73, 0x70, 0x32, 0x2E, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2E, 0x70, 0x6C, 0x61, 0x79, 0x73, 0x74, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x6E, 0x65, 0x74, 0x2F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x2F, 0x70, 0x73, 0x70, 0x32, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x2F, 0x32, 0x30, 0x31, 0x32, 0x5F, 0x30, 0x32, 0x30, 0x36, 0x2F, 0x70, 0x72, 0x65, 0x5F, 0x66, 0x62, 0x35, 0x36, 0x35, 0x66, 0x38, 0x32, 0x64, 0x36, 0x36, 0x62, 0x62, 0x64, 0x31, 0x61, 0x63, 0x39, 0x64, 0x62, 0x63, 0x32, 0x64, 0x64, 0x62, 0x31, 0x63, 0x36, 0x32, 0x63, 0x64, 0x66, 0x2F, 0x50, 0x53, 0x50, 0x32, 0x55, 0x50, 0x44, 0x41, 0x54, 0x2E, 0x50, 0x55, 0x50, 0x3F, 0x64, 0x65, 0x73, 0x74, 0x3D, 0x75, 0x73, 0x3C, 0x2F, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x3E, 0x0A, 0x3C, 0x2F, 0x72, 0x65, 0x63, 0x6F, 0x76, 0x65, 0x72, 0x79, 0x3E, 0x0A, 0x3C, 0x2F, 0x72, 0x65, 0x67, 0x69, 0x6F, 0x6E, 0x3E, 0x0A, 0x3C, 0x2F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x64, 0x61, 0x74, 0x61, 0x5F, 0x6C, 0x69, 0x73, 0x74, 0x3E, 0x0A
};

void *vita_event_listener(LIBMTP_mtpdevice_t *device);

int event_listen;

void *vita_event_listener(LIBMTP_mtpdevice_t *device)
{
    LIBMTP_event_t event;
    int event_id;
    settings_info_t info;
    unsigned char *temp;
    while(event_listen)
    {
        if(LIBMTP_Read_Event(device, &event) < 0)
        {
            fprintf(stderr, "Error recieving event.\n");
        }
        event_id = event.Param1;
        fprintf(stderr, "Event: 0x%x id %d\n", event.Code, event_id);
        switch(event.Code)
        {
            case PTP_EC_VITA_RequestGetSettingInfo:
                VitaMTP_GetSettingInfo(device, event_id, &info);
                VitaMTP_ReportResult(device, event_id, PTP_RC_OK);
            case PTP_EC_VITA_RequestSendHttpObjectFromURL:
                VitaMTP_GetUrl(device, event_id, temp);
                VitaMTP_SendHttpObjectFromURL(device, event_id, 0x3ca, data2);
                VitaMTP_ReportResult(device, event_id, PTP_RC_OK);
                break;
			case PTP_EC_VITA_RequestSendStorageSize:
				VitaMTP_SendStorageSize(device, event_id, (uint64_t)100*1024*1024*1024, (uint64_t)50*1024*1024*1024); // Send fake 50GB/100GB
				VitaMTP_ReportResult(device, event_id, PTP_RC_OK);
				break;
        }
    }
    
    return NULL;
}

int main(int argc, char** argv)
{
    LIBMTP_error_number_t err;
    
    LIBMTP_Set_Debug(9);
    
    LIBMTP_Init();
    
    LIBMTP_mtpdevice_t *device;
    pthread_t event_thread;
    PTPParams *params;
    
    device = LIBVitaMTP_Get_First_Vita();
    if (device == NULL)
    {
        fprintf(stderr, "Unable to open Vita\n");
        return 1;
    }
    
    params = (PTPParams*)device->params;
    
    event_listen = 1;
    if(pthread_create(&event_thread, NULL, (void*(*)(void*))vita_event_listener, device) != 0)
    {
        fprintf(stderr, "Cannot create event listener thread.\n");
        return 1;
    }
    
    vita_info_t info;
    initiator_info_t info2;
    info2.raw_len = 0xd0;
    info2.raw_xml = data;
    VitaMTP_GetVitaInfo(device, &info);
    VitaMTP_SendInitiatorInfo(device, &info2);
    VitaMTP_SendHostStatus(device, VITA_HOST_STATUS_Connected);
    
    sleep(120);
    
    event_listen = 0;
    VitaMTP_SendHostStatus(device, VITA_HOST_STATUS_EndConnection);
    
    LIBMTP_Release_Device(device);
    
    printf("OK.\n");
    
    return 0;
}