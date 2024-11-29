# Gunakan Node.js 20
FROM node:20

# Set working directory
WORKDIR /app

# Salin file package.json dan install dependencies
COPY package*.json ./
RUN npm install --production

# Salin seluruh kode aplikasi ke dalam container
COPY . .

# Ekspos port aplikasi
EXPOSE 8080

# Jalankan aplikasi
CMD ["npm", "start"]
