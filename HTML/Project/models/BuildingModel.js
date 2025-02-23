//For the Buildings
const mongoose = require('mongoose');
const BuildingSchema = new mongoose.Schema({
    name: { type: String, required: true },
    // location: {
    //   type: { type: String, default: 'Point' },
    //   coordinates: [longitude,latitiude]
    // },
    roomno: { type: String, required: true},
    events: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Event' }]
  });
  module.exports = mongoose.model('Building', BuildingSchema);
  // buildingSchema.index({ location: '2dsphere' });