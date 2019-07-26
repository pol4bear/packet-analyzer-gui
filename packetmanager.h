#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <pcap.h>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class PacketManager
{
public:
    PacketManager();
    void getInterfaces(vector<string> *interfaces);
    void setInterface(string *interface);
    void nextPacket(u_char *packetOut, uint *sizeOfPacket);

private:
    class ErrorMessages
    {
    public:
        string receiveFailed = "Cannot receive packet from ";
    };

    ErrorMessages errorMessages;
    string *ifname;
    pcap_t *handle;
};

#endif // PACKETMANAGER_H
