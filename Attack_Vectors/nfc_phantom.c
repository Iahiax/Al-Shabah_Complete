// nfc_phantom.c - استنساخ بطاقات NFC و Mifare
void nfc_clone_tag(void) {
    system("nfc-mfclassic r a cloned_card.mfd");
    printf("[*] NFC tag cloned to cloned_card.mfd\n");
}
