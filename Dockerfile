FROM registry.access.redhat.com/redhat/rhel:9  # Or any base image you prefer (e.g., debian:latest)

# Install OpenSSH with a specific patched version (replace with actual patched version)
RUN apk add --no-cache openssh=9.8_p1-r0

# ... (rest of your Dockerfile instructions)


