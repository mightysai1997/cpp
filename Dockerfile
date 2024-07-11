FROM debian:bullseye-slim

# Install necessary packages
RUN apt-get update && \
    apt-get install -y bookworm=1:9.2p1-2+deb12u2

# Save the container as an image
CMD ["bash"]
