module;
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <bits/socket.h>
#include <sys/epoll.h>
#include <vector>
#include <utility>
#include <iostream>
export module RemoteClient;

import Core;

export 
{
	template <typename T>
	concept RemoteClient = requires (T t)
	{
		{remoteIP (t)} -> String;
		{remotePort (t)} -> Same <int>;
	};

	struct remote_client_t
	{
		remote_client_t(int remote_sockid) noexcept : _remote_sockid {remote_sockid}
		{
			auto remote_addr = sockaddr_storage {};
			
			socklen_t remote_len = sizeof (remote_addr);

			getpeername(remote_sockid, (struct sockaddr *)&remote_addr, &remote_len);

			// deal with both IPv4 and IPv6:
			if (remote_addr.ss_family == AF_INET)
			{
				struct sockaddr_in *s = (struct sockaddr_in *)&remote_addr;
				_remote_port = ntohs(s->sin_port);
				inet_ntop(AF_INET, &s->sin_addr, _remote_ip_address, sizeof _remote_ip_address);
			}
			else
			{ // AF_INET6
				struct sockaddr_in6 *s = (struct sockaddr_in6 *)&remote_addr;
				_remote_port = ntohs(s->sin6_port);
				inet_ntop(AF_INET6, &s->sin6_addr, _remote_ip_address, sizeof _remote_ip_address);
			}

			fcntl(_remote_sockid, F_SETFL, O_NONBLOCK | FASYNC);
		}
		remote_client_t(remote_client_t && o) = default;
		//  : _remote_port {o._remote_port}, _remote_sockid {o._remote_sockid}
		// {

		// }
		remote_client_t(remote_client_t const &) = delete;
		friend auto remoteIP(remote_client_t const& me) -> std::string
		{
			return me._remote_ip_address;
		}
		friend auto remotePort (remote_client_t const& me) -> int 
		{
			return me._remote_port;
		}

		friend auto operator<<(std::ostream &os, remote_client_t const &me) -> std::ostream &
		{
			os << me._remote_ip_address << ":" << me._remote_port;
			return os;
		}

	private:
		// sockaddr_storage _addr;
		char _remote_ip_address[INET6_ADDRSTRLEN];
		int _remote_port;
		int _remote_sockid;
	};
}