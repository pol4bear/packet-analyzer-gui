#include "packetmanager.h"

PacketManager::PacketManager(){

}

// Throws runtime_error with error message on fail to open interface
void PacketManager::setInterface(string *interface){
    char errbuf[PCAP_ERRBUF_SIZE];

    ifname = interface;

    handle = pcap_open_live(ifname->c_str(), BUFSIZ, 1, 1000, errbuf);

    if(handle != nullptr) return;

    throw runtime_error(errbuf);
}

// Throws runtime_error with error message on fail to get devices
void PacketManager::getInterfaces(vector<string> *interfaces){
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *interface;

    if(pcap_findalldevs(&interface, errbuf) == -1) throw runtime_error(errbuf);

    for(; interface != nullptr; interface = interface->next)
    {
        interfaces->push_back(interface->name);
    }
}

// Throws runtime_error with error message on fail to receive next packet
void PacketManager::nextPacket(u_char *packetOut, uint *sizeOfPacket){
    struct pcap_pkthdr* header;
    const u_char* packet;

    *sizeOfPacket = 0;

    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) return;
    if (res == -1 || res == -2) throw runtime_error(errorMessages.receiveFailed.append(*ifname));

    packetOut = const_cast<u_char*>(packet);
    *sizeOfPacket = header->caplen;
}
