const express = require('express');
const mongoose = require('mongoose');
const dotenv = require('dotenv');

dotenv.config();

const app = express();
app.use(express.json());

mongoose.connect(process.env.MONGODB_URI, { useNewUrlParser: true, useUnifiedTopology: true });

const authRoutes = require('./middleware/auth');
const eventRoutes = require('./routes/events');
const buildingRoutes = require('./routes/buildings');

app.use('/api/auth', authRoutes);
app.use('/api/events', eventRoutes);
app.use('/api/buildings', buildingRoutes);


const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
