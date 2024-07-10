# Use Debian 12 (Bookworm) as the base image
FROM almalinux:9


# Install specific version of OpenSSH
RUN apt-get update && \
    apt-get install -y 	openssh=8.5p1

# Optionally, install OpenSSL if needed for compatibility
RUN apt-get install -y openssl

# Generate host keys for SSH (if not already generated)
RUN ssh-keygen -A

# Expose SSH port
EXPOSE 22

# Start SSH service
CMD ["/usr/sbin/sshd", "-D"]
