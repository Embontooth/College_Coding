const buildingSchema = new mongoose.Schema({
    name: { type: String, required: true },
    location: {
      type: { type: String, default: 'Point' },
      coordinates: [Number]
    },
    events: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Event' }]
  });
  
  buildingSchema.index({ location: '2dsphere' });

  
  const eventSchema = new mongoose.Schema({
    name: { type: String, required: true },
    building: { type: mongoose.Schema.Types.ObjectId, ref: 'Building', required: true },
    location: {
      type: { type: String, default: 'Point' },
      coordinates: [Number]
    },
    startTime: { type: Date, required: true },
    endTime: { type: Date, required: true },
    information: { type: String },
    categories: [{ type: String }],
    createdBy: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
    temporaryEditor: {
      userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
      expiresAt: { type: Date }
    }
  });
  
  eventSchema.index({ location: '2dsphere' });
  eventSchema.index({ name: 'text', information: 'text', categories: 'text' });

  
  const userSchema = new mongoose.Schema({
    username: { type: String, required: true, unique: true },
    password: { type: String, required: true },
    role: { type: String, enum: ['normal', 'club_leader'], default: 'normal' }
  });
  